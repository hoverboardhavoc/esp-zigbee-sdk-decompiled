/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_setup_response_with_extension
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
  byte bVar1;
  zcl_status_t zVar2;
  undefined3 in_register_00002035;
  undefined3 in_register_00002039;
  
  if (rsp == (zcl_packet_t *)0x0) {
    zVar2 = 0x87;
  }
  else if (req == (zcl_packet_t *)0x0) {
    zVar2 = 0x87;
  }
  else {
    (rsp->header).tsn = (req->header).tsn;
    (rsp->header).cmd_id = cmd_id;
    (rsp->header).manuf_code = (req->header).manuf_code;
    bVar1 = (req->header).fc;
    (rsp->header).fc = bVar1;
    if ((bVar1 & 8) == 0) {
      (rsp->header).fc = bVar1 | 8;
    }
    else {
      (rsp->header).fc = bVar1 & 0xf7;
    }
    if (CONCAT31(in_register_00002039,dis_def_rsp) == 0) {
      (rsp->header).fc = (rsp->header).fc & 0xef;
    }
    else {
      (rsp->header).fc = (rsp->header).fc | 0x10;
    }
    zcl_packet_setup_stamp
              (rsp,(req->header).dst_ep,(req->header).src_ep,(req->header).cluster_id,
               (req->header).profile_id,(req->header).src_addr.addr_mode,
               (uint8_t *)&(req->header).src_addr.u.short_addr);
    if (CONCAT31(in_register_00002035,new_tsn) == 0) {
      (rsp->header).tsn = (req->header).tsn;
      (rsp->header).fc = (rsp->header).fc | 0x20;
      zVar2 = '\0';
    }
    else {
      (rsp->header).tsn = 0xff;
      (rsp->header).fc = (rsp->header).fc & 0xdf;
      zVar2 = '\0';
    }
  }
  return zVar2;
}

