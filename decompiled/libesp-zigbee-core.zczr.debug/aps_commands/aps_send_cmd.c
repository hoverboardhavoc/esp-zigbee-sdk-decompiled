/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_send_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_send_cmd(zmsg_t *msg,ezb_extaddr_t *dst_addr)

{
  undefined3 uVar1;
  uint uVar2;
  ezb_err_t eVar3;
  int iVar4;
  byte bVar5;
  zmsg_t *local_30;
  aps_apsde_data_req_t aps_req;
  ezb_shortaddr_t dst_shortaddr;
  uint8_t fcf;
  
  uVar2 = zmsg_get_length();
  if (uVar2 < 0x5b) {
    aps_req.asdu = (zmsg_t *)0x0;
    aps_req.dst_addr._0_4_ = 0;
    aps_req.dst_addr.u._2_4_ = 0;
    aps_req._12_4_ = 0;
    aps_req.cluster_id = 0;
    aps_req.profile_id = 0;
    aps_req.radius = '\0';
    aps_req.alias_seq_num = '\0';
    aps_req.alias_src_addr = 0;
    local_30 = msg;
    zmsg_read_bytes(msg,0,1,&aps_req.field_0x1b);
    uVar1 = SUB43(aps_req._20_4_,1);
    bVar5 = (byte)aps_req._27_1_ >> 5 & 1 |
            (byte)aps_req._20_4_ & 0xfc | (byte)(((byte)aps_req._27_1_ >> 6 & 1) << 1);
    aps_req._21_3_ = uVar1;
    aps_req.radius = bVar5;
    if ((*(int *)&dst_addr->field_0 == -1) && (*(int *)((int)&dst_addr->field_0 + 4) == -1)) {
      aps_req.field_9 = (anon_union_1_2_0b76fd53_for_aps_apsde_data_req_s_9)0xfd;
      aps_req._25_1_ = 0xff;
      aps_req._20_4_ = CONCAT31(uVar1,bVar5) & 0xfffffffc;
      goto _L0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_commands.c",0x3b,
                  "aps_send_cmd","zmsg_get_length(msg) <= 90");
  }
  iVar4 = nwk_address_short_by_extended(dst_addr,&aps_req.field_9);
  if (iVar4 != 0) {
    return iVar4;
  }
_L0:
  zmsg_add_footer(msg,&local_30,0x1c);
  if ((aps_req._20_4_ & 2) == 0) {
    eVar3 = aps_send_frame(aps_req._24_2_,&local_30);
  }
  else {
    eVar3 = aps_retrans_send_msg(aps_req._24_2_,0x5a,&local_30);
  }
  return eVar3;
}

