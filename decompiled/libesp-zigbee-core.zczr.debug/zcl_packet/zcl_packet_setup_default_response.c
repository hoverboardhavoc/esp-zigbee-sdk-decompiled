/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_setup_default_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_packet_setup_default_response(zcl_packet_t *rsp,zcl_packet_t *req,uint8_t status)

{
  int iVar1;
  zcl_status_t zVar2;
  undefined3 extraout_var;
  undefined3 in_register_00002031;
  byte bVar3;
  uint8_t auStack_21 [13];
  
  if (req == (zcl_packet_t *)0x0) {
    iVar1 = 0x87;
  }
  else if (rsp == (zcl_packet_t *)0x0) {
    iVar1 = 0x87;
  }
  else if ((req->header).dst_addr.u.short_addr < 0xfff8) {
    bVar3 = (req->header).fc;
    if (((bVar3 & 3) == 0) && ((req->header).cmd_id == '\v')) {
      iVar1 = 0xfe;
    }
    else if (CONCAT31(in_register_00002031,status) == 0xfe) {
      iVar1 = 0xfe;
    }
    else if (((bVar3 & 0x10) == 0) || (CONCAT31(in_register_00002031,status) != 0)) {
      zVar2 = zcl_packet_setup_response(rsp,req,'\v');
      iVar1 = CONCAT31(extraout_var,zVar2);
      if (iVar1 == 0) {
        bVar3 = (rsp->header).fc & 0xfc;
        (rsp->header).fc = bVar3;
        (rsp->header).fc = bVar3 | 0x10;
        if (rsp->payload == (zcl_packet_payload_t *)0x0) {
          iVar1 = 0x85;
        }
        else {
          zmsg_set_length(0);
          auStack_21[0] = (req->header).cmd_id;
          zmsg_append_bytes(rsp->payload,1,auStack_21);
          auStack_21[0] = status;
          zmsg_append_bytes(rsp->payload,1,auStack_21);
        }
      }
    }
    else {
      iVar1 = 0xfe;
    }
  }
  else {
    iVar1 = 0xfe;
  }
  return (zcl_status_t)iVar1;
}

