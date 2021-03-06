#include <cmath>

#include <psf/Error.h>
#include "psf/PeakShape.h"

using namespace psf;

double LorentzianPeakShape::at(const double xCoordinate) const {
    return fwhm_ / ((xCoordinate * xCoordinate) + (fwhm_*fwhm_));
}

double LorentzianPeakShape::getSupportThreshold() const {
    return this->getFwhm() * this->getFwhmFactorForSupportThreshold();
}

// construction
LorentzianPeakShape::LorentzianPeakShape(const double fwhm, const double fwhmFactorForSupportThreshold) 
    : fwhm_(fwhm), fwhmFactorForSupportThreshold_(fwhmFactorForSupportThreshold) {
    psf_precondition(fwhm > 0, "LorentzianPeakShape::LorentzianPeakShape(): Parameter fwhm has to be positive.");
    psf_precondition(fwhmFactorForSupportThreshold > 0, "LorentzianPeakShape::LorentzianPeakShape(): fwhmFactorForSupportThreshold has to be positive.");
}


// setter/getter
void LorentzianPeakShape::setFwhm(const double fwhm) {
    psf_precondition(fwhm > 0, "LorentzianPeakShape::LorentzianPeakShape(): Parameter fwhm has to be positive.");
    fwhm_ = fwhm;
}
double LorentzianPeakShape::getFwhm() const {
    return fwhm_;
}

void LorentzianPeakShape::setFwhmFactorForSupportThreshold(const double factor) {
    psf_precondition(factor > 0, "LorentzianPeakShape::LorentzianPeakShape(): Parameter fwhmFactorForSupportThreshold has to be positive.");
    fwhmFactorForSupportThreshold_ = factor;
}
double LorentzianPeakShape::getFwhmFactorForSupportThreshold() const {
    return fwhmFactorForSupportThreshold_;
}
