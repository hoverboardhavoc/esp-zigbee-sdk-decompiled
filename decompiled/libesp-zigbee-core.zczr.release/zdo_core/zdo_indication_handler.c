/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_core.o -> zdo_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_indication_handler(af_data_ind_t *ind)

{
  int iVar1;
  undefined1 auStack_28 [4];
  zdo_packet_t packet;
  
  memset(auStack_28,0,0x18);
  iVar1 = 0x80;
  if ((ind != (af_data_ind_t *)0x0) &&
     (iVar1 = zdo_packet_init_with_msg(auStack_28,ind), iVar1 == 0)) {
    iVar1 = zdo_packet_indication_handler(auStack_28);
  }
  return (zdp_status_t)iVar1;
}

