/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_handle_datagram
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_handle_datagram(aps_header_t *aps_hdr,zmsg_t *msg)

{
  _Bool _Var1;
  undefined4 uVar2;
  undefined3 extraout_var;
  int iVar3;
  ezb_err_t eVar4;
  byte bVar5;
  aps_apsde_data_ind_t aStack_20;
  
  if (((((0xfff7 < (aps_hdr->addr_info).dst_addr) || ((aps_hdr->fcf & 3) != 0)) ||
       ((aps_hdr->fcf & 0x40) == 0)) || (eVar4 = aps_send_ack(aps_hdr,'\0',0xff), eVar4 == 0)) &&
     (iVar3 = aps_check_duplicates(aps_hdr), iVar3 == 0)) {
    bVar5 = aps_hdr->fcf & 3;
    if (bVar5 == 1) {
      aps_handle_cmd(aps_hdr,msg);
      return;
    }
    if (bVar5 == 2) {
      aps_retrans_handle_ack(aps_hdr,msg);
      return;
    }
    if ((aps_hdr->fcf & 3) == 0) {
      memcpy(&aStack_20,aps_hdr,0xc);
      aStack_20.asdu = msg;
      uVar2 = zmsg_get_offset(msg);
      zmsg_remove_header(msg,uVar2);
      _Var1 = aps_apsde_user_data_indication(&aStack_20);
      if (CONCAT31(extraout_var,_Var1) == 0) {
        aps_apsde_data_indication(&aStack_20);
      }
      return;
    }
  }
  if (msg == (zmsg_t *)0x0) {
    return;
  }
  zmsg_free(msg);
  return;
}

