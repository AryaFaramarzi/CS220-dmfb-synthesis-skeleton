//
// Created by Arya on 8/17/20.
//

#ifndef CS220SYNTH_VOLUME_AWARE_PIN_MAPPER_H
#define CS220SYNTH_VOLUME_AWARE_PIN_MAPPER_H

#include "dmfb_arch.h"
#include "pin_mapper.h"
#include "claim.h"

class VolumeAwarePinMapper : public PinMapper {

public:
    // Constructors & Destructor
    VolumeAwarePinMapper();
    VolumeAwarePinMapper(DmfbArch *dmfbArch);
    virtual ~VolumeAwarePinMapper();

    // Methods
    void setCustomMapping() override;
    void setMapPreSched() override;
    void setMapPostRoute(vector<vector<int> *> *pinActivations, map<Droplet *, vector<RoutePoint *> *> *routes) override;
    void flattenSpecialPurposePins() override;
    void unflattenSpecialPurposePins() override;

    // Getters/Setter

protected:
    // Methods
    int computeAvailResources();

    // Members
    DmfbArch *arch;

};


#endif //CS220SYNTH_VOLUME_AWARE_PIN_MAPPER_H
