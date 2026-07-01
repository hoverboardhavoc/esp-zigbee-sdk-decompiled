/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_setup_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010502) */
/* WARNING: Removing unreachable block (ram,0x00010530) */
/* WARNING: Unknown calling convention */

zcl_status_t zcl_packet_setup_response(zcl_packet_t *rsp,zcl_packet_t *req,uint8_t cmd_id)

{
  uint8_t uVar1;
  byte bVar2;
  zcl_status_t zVar3;
  byte bVar4;
  
  if (rsp != (zcl_packet_t *)0x0) {
    zVar3 = 0x87;
    if (req != (zcl_packet_t *)0x0) {
      uVar1 = (req->header).tsn;
      (rsp->header).cmd_id = cmd_id;
      (rsp->header).tsn = uVar1;
      (rsp->header).manuf_code = (req->header).manuf_code;
      bVar2 = (req->header).fc;
      bVar4 = bVar2 | 8;
      if ((bVar2 & 8) != 0) {
        bVar4 = bVar2 & 0xf7;
      }
      (rsp->header).fc = bVar4 & 0xef;
      zcl_packet_setup_stamp
                (rsp,(req->header).dst_ep,(req->header).src_ep,(req->header).cluster_id,
                 (req->header).profile_id,(req->header).src_addr.addr_mode,
                 (uint8_t *)&(req->header).src_addr.u.short_addr);
      (rsp->header).tsn = (req->header).tsn;
      (rsp->header).fc = bVar4 & 0xef | 0x20;
      zVar3 = '\0';
    }
    return zVar3;
  }
  return 0x87;
}

