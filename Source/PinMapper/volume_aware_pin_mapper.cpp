//
// Created by Arya on 8/17/20.
//

#include "volume_aware_pin_mapper.h"
#include "sort.h"

///////////////////////////////////////////////////////////////////////////////////
// Constructors
///////////////////////////////////////////////////////////////////////////////////
VolumeAwarePinMapper::VolumeAwarePinMapper() {
    arch = NULL;
}
VolumeAwarePinMapper::VolumeAwarePinMapper(DmfbArch *dmfbArch) {
 arch = dmfbArch;
}

///////////////////////////////////////////////////////////////////////////////////
// Deconstructor
///////////////////////////////////////////////////////////////////////////////////
VolumeAwarePinMapper::~VolumeAwarePinMapper() {
    delete arch;
}


///////////////////////////////////////////////////////////////////////////////////
// This function maps the chip based on the volume of the droplet. According to the
// DAG at each step, the modules sizes will be modified.
///////////////////////////////////////////////////////////////////////////////////
void VolumeAwarePinMapper::setCustomMapping() {


    computeAvailResources();
}

///////////////////////////////////////////////////////////////////////////////////
// This function should be overridden; it is called just before scheduling.
///////////////////////////////////////////////////////////////////////////////////
void VolumeAwarePinMapper::setMapPreSched() {
    initPinMapping();
    setCustomMapping();
}

///////////////////////////////////////////////////////////////////////////////////
// This function should be overridden; it is called just after routing.
///////////////////////////////////////////////////////////////////////////////////
void VolumeAwarePinMapper::setMapPostRoute(vector<vector<int> *> *pinActivations,
                                           map<Droplet *, vector<RoutePoint *> *> *routes) {
    // Do nothing...mapping set at beginning.
}

///////////////////////////////////////////////////////////////////////////////////
// This function should be overridden; it is called to flatten all of the special-
// purpose pin vectors for a particular pin-mapper into a single vector that
// can be written to file. It is arranged such that a single number dictating
// directly the length of the next sub-list exists before each sub-list.
//
// NOTE: Order MUST match with unflattenSpecialPurposePins().
///////////////////////////////////////////////////////////////////////////////////
void VolumeAwarePinMapper::flattenSpecialPurposePins() {

}

///////////////////////////////////////////////////////////////////////////////////
// This function should be overridden; it is called to un-flatten the single
// special-purpose pin vector into all of the special-purpose pin vectors
// (for reading from file). It is arranged such that a single number dictating
// directly the length of the next sub-list exists before each sub-list.
//
// NOTE: Order MUST match with flattenSpecialPurposePins().
///////////////////////////////////////////////////////////////////////////////////
void VolumeAwarePinMapper::unflattenSpecialPurposePins() {
}

///////////////////////////////////////////////////////////////////////////////////
// Computes the available resources based on the provided resource-allocation type.
///////////////////////////////////////////////////////////////////////////////////
int VolumeAwarePinMapper::computeAvailResources() {
    return 0;
}



