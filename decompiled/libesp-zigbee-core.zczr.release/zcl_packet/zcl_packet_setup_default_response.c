/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_setup_default_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_packet_setup_default_response(zcl_packet_t *rsp,zcl_packet_t *req,uint8_t status)

{
  byte bVar1;
  int iVar2;
  zcl_status_t zVar3;
  undefined3 extraout_var;
  zcl_packet_payload_t *pzVar4;
  undefined3 in_register_00002031;
  uint8_t uStack_11;
  
  iVar2 = CONCAT31(in_register_00002031,status);
  if ((req == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
_L0:
    iVar2 = 0x87;
  }
  else {
    if (((req->header).dst_addr.u.short_addr < 0xfff8) &&
       ((bVar1 = (req->header).fc, (bVar1 & 3) != 0 || ((req->header).cmd_id != '\v')))) {
      if (iVar2 == 0xfe) goto _L0;
      if (((bVar1 & 0x10) == 0) || (iVar2 != 0)) {
        zVar3 = zcl_packet_setup_response(rsp,req,'\v');
        if (CONCAT31(extraout_var,zVar3) == 0) {
          pzVar4 = rsp->payload;
          (rsp->header).fc = (rsp->header).fc & 0xfc | 0x10;
          if (pzVar4 == (zcl_packet_payload_t *)0x0) {
            iVar2 = 0x85;
          }
          else {
            zmsg_set_length(0);
            uStack_11 = (req->header).cmd_id;
            zmsg_append_bytes(rsp->payload,1,&uStack_11);
            uStack_11 = status;
            zmsg_append_bytes(rsp->payload,1,&uStack_11);
            iVar2 = 0;
          }
          goto _L0;
        }
        goto _L0;
      }
    }
    iVar2 = 0xfe;
  }
_L0:
  return (zcl_status_t)iVar2;
}

