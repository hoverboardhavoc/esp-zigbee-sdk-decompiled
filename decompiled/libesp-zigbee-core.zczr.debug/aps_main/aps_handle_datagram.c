/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_handle_datagram
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_handle_datagram(aps_header_t *aps_hdr,zmsg_t *msg)

{
  _Bool _Var1;
  undefined3 extraout_var;
  ezb_err_t eVar2;
  int iVar3;
  byte bVar4;
  
  _Var1 = aps_frame_need_ack(aps_hdr);
  if (((CONCAT31(extraout_var,_Var1) == 0) ||
      (eVar2 = aps_send_ack(aps_hdr,msg,'\0',0xff), eVar2 == 0)) &&
     (iVar3 = aps_check_duplicates(aps_hdr), iVar3 == 0)) {
    bVar4 = aps_hdr->fcf & 3;
    if (bVar4 == 1) {
      aps_handle_cmd(aps_hdr,msg);
      return;
    }
    if (bVar4 == 2) {
      aps_retrans_handle_ack(aps_hdr,msg);
      return;
    }
    if ((aps_hdr->fcf & 3) == 0) {
      aps_handle_data(aps_hdr,msg);
      return;
    }
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}

