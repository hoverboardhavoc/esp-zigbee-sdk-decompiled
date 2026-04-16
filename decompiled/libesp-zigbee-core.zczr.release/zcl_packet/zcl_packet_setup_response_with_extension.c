/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_setup_response_with_extension
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t
zcl_packet_setup_response_with_extension
          (zcl_packet_t *rsp,zcl_packet_t *req,uint8_t cmd_id,_Bool new_tsn,_Bool dis_def_rsp)

{
  uint8_t uVar1;
  zcl_status_t zVar2;
  undefined3 in_register_00002035;
  undefined3 in_register_00002039;
  byte bVar3;
  byte bVar4;
  
  if (rsp != (zcl_packet_t *)0x0) {
    zVar2 = 0x87;
    if (req != (zcl_packet_t *)0x0) {
      uVar1 = (req->header).tsn;
      (rsp->header).cmd_id = cmd_id;
      (rsp->header).tsn = uVar1;
      (rsp->header).manuf_code = (req->header).manuf_code;
      bVar4 = (req->header).fc;
      bVar3 = bVar4 | 8;
      if ((bVar4 & 8) != 0) {
        bVar3 = bVar4 & 0xf7;
      }
      bVar4 = bVar3 & 0xef;
      if (CONCAT31(in_register_00002039,dis_def_rsp) != 0) {
        bVar4 = bVar3 | 0x10;
      }
      (rsp->header).fc = bVar4;
      zcl_packet_setup_stamp
                (rsp,(req->header).dst_ep,(req->header).src_ep,(req->header).cluster_id,
                 (req->header).profile_id,(req->header).src_addr.addr_mode,
                 (uint8_t *)&(req->header).src_addr.u.short_addr);
      if (CONCAT31(in_register_00002035,new_tsn) == 0) {
        bVar4 = bVar4 | 0x20;
        (rsp->header).tsn = (req->header).tsn;
      }
      else {
        (rsp->header).tsn = 0xff;
        bVar4 = bVar4 & 0xdf;
      }
      (rsp->header).fc = bVar4;
      zVar2 = '\0';
    }
    return zVar2;
  }
  return 0x87;
}

