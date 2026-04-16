/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_parse_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_frame_parse_header(ezb_radio_frame_t *radio_frame,mac_header_t *mhr,uint8_t *mhr_len)

{
  ushort uVar1;
  uint8_t uVar2;
  ezb_err_t eVar3;
  int iVar4;
  ezb_err_t eVar5;
  undefined3 extraout_var;
  ushort *puVar6;
  
  if (radio_frame == (ezb_radio_frame_t *)0x0) {
    iVar4 = 0;
    eVar3 = 2;
  }
  else if (mhr == (mac_header_t *)0x0) {
    iVar4 = 0;
    eVar3 = 2;
  }
  else {
    eVar3 = mac_frame_validate_psdu(radio_frame);
    if (eVar3 == 0) {
      puVar6 = (ushort *)radio_frame->psdu;
      uVar1 = *puVar6;
      mhr->fcf = uVar1;
      eVar3 = mac_frame_get_seq_num(radio_frame,&mhr->seq_num);
      if ((eVar3 == 0) || ((uVar1 & 0x3000) == 0x2000)) {
        eVar3 = mac_frame_get_dstaddr(radio_frame,&mhr->dst_addr);
        if (eVar3 == 0) {
          eVar3 = mac_frame_get_srcaddr(radio_frame,&mhr->src_addr);
          if (eVar3 == 0) {
            eVar5 = mac_frame_get_dst_panid(radio_frame,&mhr->dst_panid);
            if (eVar5 != 0) {
              mhr->dst_panid = 0xffff;
            }
            eVar5 = mac_frame_get_src_panid(radio_frame,&mhr->src_panid);
            if (eVar5 != 0) {
              mhr->src_panid = mhr->dst_panid;
            }
            uVar2 = mac_frame_find_payload_index(radio_frame);
            iVar4 = CONCAT31(extraout_var,uVar2);
            if ((uVar1 & 7) == 3) {
              mhr->cmd_id = *(uint8_t *)((int)puVar6 + iVar4);
            }
            else {
              mhr->cmd_id = '\0';
            }
          }
          else {
            iVar4 = 0;
          }
        }
        else {
          iVar4 = 0;
        }
      }
      else {
        iVar4 = 0;
        eVar3 = 0x10;
      }
    }
    else {
      iVar4 = 0;
    }
  }
  if (mhr_len != (uint8_t *)0x0) {
    *mhr_len = (uint8_t)iVar4;
  }
  return eVar3;
}

