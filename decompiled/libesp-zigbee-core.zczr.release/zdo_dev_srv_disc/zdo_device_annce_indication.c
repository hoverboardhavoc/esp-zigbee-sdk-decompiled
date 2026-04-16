/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_dev_srv_disc.o -> zdo_device_annce_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_device_annce_indication(ezb_extaddr_t ieee_addr,uint16_t nwk_addr,uint8_t capability)

{
  undefined2 in_register_0000202a;
  undefined3 in_register_0000202d;
  
  log_write(3,"ZDO_DEV_SRV_DISC",
            "ZDO Device Announcement Indication: IEEE=0x%llx, NWK=0x%04x, Capability=0x%02x",
            CONCAT22(in_register_0000202a,nwk_addr),CONCAT31(in_register_0000202d,capability));
  return;
}

