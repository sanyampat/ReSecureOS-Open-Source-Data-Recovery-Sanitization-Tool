#pragma once

#include "DeviceCapabilities.h"
#include "SanitizationResult.h"

namespace core::sanitization {

/// SCSI Sanitize command (SCSI Block Commands — SBC-4).
///
/// SANITIZE is used for device-level sanitization when supported.
/// FORMAT UNIT is retained only as a separate CLEAR-class fallback
/// and must not be treated as equivalent to SANITIZE/PURGE.
///
/// The result reports the actual method and assurance level used.
class ScsiSanitizer {
public:
    ScsiSanitizer()  = default;
    ~ScsiSanitizer() = default;

    SanitizationResult purge(const DeviceCapabilities& caps) const;

private:
    SanitizationResult scsiSanitize  (int fd, const DeviceCapabilities& caps) const;
    SanitizationResult scsiFormatUnit(int fd, const DeviceCapabilities& caps) const;
    bool pollScsiSanitize(int fd, unsigned timeoutSec = 600) const;
};

} // namespace core::sanitization