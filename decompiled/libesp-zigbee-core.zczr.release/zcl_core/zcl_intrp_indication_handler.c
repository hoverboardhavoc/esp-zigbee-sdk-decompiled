/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_core.o -> zcl_intrp_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_intrp_indication_handler(af_intrp_data_ind_t *ind)

{
  int iVar1;
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  memset(auStack_38,0,0x28);
  iVar1 = zcl_packet_init_with_intrp_ind(auStack_38,ind);
  if (iVar1 == 0) {
    iVar1 = 0x85;
    if (packet.header._20_2_ == -0x3fa2) {
      iVar1 = zcl_touchlink_handler(auStack_38);
      if (iVar1 == 0) goto _L0;
      if (iVar1 == 0xfe) goto _L0;
    }
    iVar1 = zcl_packet_send_default_response(auStack_38,iVar1);
  }
  else {
_L0:
    iVar1 = 0xfe;
  }
_L0:
  return (zcl_status_t)iVar1;
}

