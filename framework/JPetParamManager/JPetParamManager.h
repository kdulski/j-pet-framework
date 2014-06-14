// JPetParamManager.h - JPetParamManager
#ifndef _J_PET_PARAM_MANAGER_
#define _J_PET_PARAM_MANAGER_

#include <vector>
#include <cassert>
#include <string>
#include <iostream>
//#include <TFile.h>
//#include <TList.h>

#include "../JPetScin/JPetScin.h"
#include "../JPetPM/JPetPM.h"
#include "../JPetKB/JPetKB.h"
#include "../JPetTRB/JPetTRB.h"
#include "../JPetTOMB/JPetTOMB.h"


class JPetParamManager
{
public:
  enum ContainerType {kScintillator, kPM, kKB, kTRB, kTOMB};
  
protected:
  std::string fScintilatorsObjectName;
  std::string fPMsObjectName;
  std::string fKBsObjectName;
  std::string fTRBsObjectName;
  std::string fTOMBsObjectName;
  
  std::vector<JPetScin> fScintillators;
  std::vector<JPetPM>   fPMs;
  std::vector<JPetKB>   fKBs;
  std::vector<JPetTRB>  fTRBs;
  std::vector<JPetTOMB> fTOMBs;	// always one-piece vector
  
public:
  JPetParamManager(void);
  JPetParamManager(const std::string &p_scintilatorsObjectName,
		   const std::string &p_PMsObjectName,
		   const std::string &p_KBsObjectName,
		   const std::string &p_TRBsObjectName,
		   const std::string &p_TOMBsObjectName);
  ~JPetParamManager(void);
  
  void readFile(const char* file_name);
  
  void fillScintillators(const int p_run_id);
  void fillPMs(const int p_run_id);
  void fillKBs(const int p_run_id);
  void fillTRBs(const int p_run_id);
  void fillTOMBs(const int p_run_id);
  
  void fillKBInputOutputData(void);
  void fillTRBInputOutputData(void);
  
  void fillScintillatorsTRefs(void);
  void fillPMsTRefs(void);
  void fillKBsTRefs(void);
  void fillTRBsTRefs(void);
  
  void fillContainers(const int p_run_id);
  void fillContainers(const JPetParamManager::ContainerType &p_containerType, const char *p_fileName);
  
  void fillContainersTRefs(void);
  void fillContainersTRefs(const JPetParamManager::ContainerType &p_containerType);
  
  void generateRootFile(const JPetParamManager::ContainerType &p_containerType, const char *p_fileName);
  
  const std::vector<JPetScin>& getScintillators() const { return fScintillators; }
  const std::vector<JPetPM>&   getPMs()           const { return fPMs;           }
  const std::vector<JPetKB>&   getKBs()           const { return fKBs;           }
  const std::vector<JPetTRB>&  getTRBs()          const { return fTRBs;          }
  const std::vector<JPetTOMB>& getTOMBs()         const { return fTOMBs;         }
  
  bool getScintillatorData(unsigned int p_index, JPetScin &p_data);
  bool getPMData(unsigned int p_index, JPetPM &p_data);
  bool getKBData(unsigned int p_index, JPetKB &p_data);
  bool getTRBData(unsigned int p_index, JPetTRB &p_data);
  bool getTOMBData(unsigned int p_index, JPetTOMB &p_data);
  
  template <typename T>
  const std::vector<T>& getContainer(const JPetParamManager::ContainerType &p_containerType) const	// not working
  {
    switch(p_containerType) 
    {
    case kScintillator:
      return fScintillators;
    case kPM:
      return fPMs;
    case kKB:
      return fKBs;
    case kTRB:
      return fTRBs;
    case kTOMB:
      return fTOMBs;
      
    default:
      assert(1 == 0);	// consider
    }
  }
  
  template <typename T>
  bool getData(const JPetParamManager::ContainerType &p_containerType, unsigned int p_index, T &p_data)	// not working
  {
    switch(p_containerType) 
    {
      case kScintillator:
      {
	if(p_index < fScintillators.size())
	{
	  p_data = fScintillators[p_index];
	  return true;
	}
      }
      case kPM:
      {
	if(p_index < fPMs.size())
	{
	  p_data = fPMs[p_index];
	  return true;
	}
      }
      case kKB:
      {
	if(p_index < fKBs.size())
	{
	  p_data = fKBs[p_index];
	  return true;
	}
      }
      case kTRB:
      {
	if(p_index < fTRBs.size())
	{
	  p_data = fTRBs[p_index];
	  return true;
	}
      }
      case kTOMB:
      {
	if(p_index < fTOMBs.size())
	{
	  p_data = fTOMBs[p_index];
	  return true;
	}
      }
    }
    
    return false;
  }
  
  int getDataSize(const JPetParamManager::ContainerType &p_containerType) const;
  
  // friend void JPetScin::clearTRefPMs();
  // friend void JPetPM::clearTRefKBs();
  // friend void JPetKB::clearTRefTRBs();
  // friend void JPetTRB::clearTRefTOMB();
  
protected:  
  void fillScintillators(const char *p_fileName);
  void fillPMs(const char *p_fileName);
  void fillKBs(const char *p_fileName);
  void fillTRBs(const char *p_fileName);
  void fillTOMBs(const char *p_fileName);
  
  void fillKBInputData(void);
  void fillKBOutputData(void);
  void fillTRBInputData(void);
  void fillTRBOutputData(void);
  
  void generateRootFileForScintillators(const char *p_fileName);
  void generateRootFileForPMs(const char *p_fileName);
  void generateRootFileForKBs(const char *p_fileName);
  void generateRootFileForTRBs(const char *p_fileName);
  void generateRootFileForTOMBs(const char *p_fileName);
};

#endif	// _J_PET_PARAM_MANAGER_
