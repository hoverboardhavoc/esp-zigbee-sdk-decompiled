/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_send_default_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: rsp */
/* WARNING: Unknown calling convention */

zcl_status_t zcl_packet_send_default_response(zcl_packet_t *packet,uint8_t status)

{
  int iVar1;
  zcl_status_t zVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined1 auStack_38 [4];
  zcl_packet_t rsp;
  
  iVar1 = 0x87;
  memset(auStack_38,0,0x28);
  if (packet != (zcl_packet_t *)0x0) {
    zVar2 = zcl_packet_init((zcl_packet_t *)auStack_38,
                            (_Bool)((byte)(*(ushort *)&(packet->header).fc >> 2) & 1));
    iVar1 = CONCAT31(extraout_var,zVar2);
    if (iVar1 == 0) {
      zVar2 = zcl_packet_setup_default_response((zcl_packet_t *)auStack_38,packet,status);
      iVar1 = CONCAT31(extraout_var_00,zVar2);
      if (iVar1 == 0) {
        zcl_packet_send((zcl_packet_t *)auStack_38,(zcl_packet_cnf_ctx_t *)0x0);
        goto _L0;
      }
    }
    if (rsp._32_4_ != 0) {
      zmsg_free();
    }
  }
_L0:
  return (zcl_status_t)iVar1;
}

