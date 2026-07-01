/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_bind_trans_schedule_next_nmsg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_bind_trans_schedule_next_nmsg
                    (aps_bind_src_t *src,aps_bind_dst_t *dst,zmsg_t *msg,uint8_t *bind_trans_cnt)

{
  zmsg_t *pzVar1;
  int iVar2;
  ezb_err_t eVar3;
  uint8_t uVar4;
  undefined1 local_40 [4];
  aps_apsde_data_req_t req;
  aps_bind_trans_ctx_t bt_ctx;
  
  local_40 = (undefined1  [4])0x0;
  req.asdu = (zmsg_t *)0x0;
  req.dst_addr._0_4_ = 0;
  req.dst_addr.u._2_4_ = 0;
  req._12_4_ = 0;
  req.cluster_id = 0;
  req.profile_id = 0;
  req.radius = '\0';
  req.alias_seq_num = '\0';
  req.alias_src_addr = 0;
  req._24_4_ = msg;
  zmsg_get_footer(msg,local_40,0x1c);
  uVar4 = '\0';
  do {
    dst = (aps_bind_dst_t *)aps_bind_table_next_dst_by_src(src,dst);
    if (((dst == (aps_bind_dst_t *)0x0) ||
        (pzVar1 = (zmsg_t *)zmsg_clone(msg), pzVar1 == (zmsg_t *)0x0)) ||
       (iVar2 = zmsg_add_footer(&req.field_9,4), iVar2 != 0)) goto _L0;
    pzVar1->flags = pzVar1->flags | 0x20;
    if ((dst->field_0x5 & 1) == 0) {
      req.asdu = (zmsg_t *)CONCAT31(req.asdu._1_3_,3);
      iVar2 = nwk_address_extended_by_ref
                        ((dst->field_0).extaddr.addr_ref,(undefined1 *)((int)&req.asdu + 2));
      if (iVar2 != 0) {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_main.c",0x127,
                      "aps_bind_trans_schedule_next_nmsg",
                      "(nwk_address_extended_by_ref(dst->extaddr.addr_ref, &req.dst_addr.u.extended_addr)) == 0"
                     );
_L0:
        if (uVar4 != '\0') {
          *bind_trans_cnt = uVar4;
        }
        return (uint)(uVar4 == '\0');
      }
      req.dst_addr.u._5_1_ = (dst->field_0).extaddr.endpoint;
    }
    else {
      req.asdu = (zmsg_t *)CONCAT22((dst->field_0).extaddr.addr_ref,1);
      req.dst_addr._0_4_ = 0xffff;
      req.dst_addr.u._2_4_ = ((uint)req.dst_addr.u._2_4_ >> 0x10 & 0xff) << 0x10;
    }
    local_40 = (undefined1  [4])pzVar1;
    eVar3 = aps_apsde_data_request((aps_apsde_data_req_t *)local_40);
    if (eVar3 == 0) {
      uVar4 = uVar4 + '\x01';
    }
  } while( true );
}

