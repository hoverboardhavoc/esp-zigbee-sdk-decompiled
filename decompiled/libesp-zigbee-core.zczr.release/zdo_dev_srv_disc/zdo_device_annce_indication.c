/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_dev_srv_disc.o -> zdo_device_annce_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_device_annce_indication
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  log_write(3,"ZDO_DEV_SRV_DISC",
            "ZDO Device Announcement Indication: IEEE=0x%llx, NWK=0x%04x, Capability=0x%02x",param_1
            ,param_2,param_3,param_4);
  return;
}

