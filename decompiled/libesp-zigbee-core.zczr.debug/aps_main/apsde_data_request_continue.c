/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> apsde_data_request_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t apsde_data_request_continue(aps_apsde_data_req_t *req,ezb_shortaddr_t dst_addr)

{
  anon_union_1_2_0b76fd53_for_aps_apsde_data_req_s_9 aVar1;
  zmsg_t *pzVar2;
  _Bool _Var3;
  uint16_t uVar4;
  undefined3 extraout_var;
  uint uVar5;
  undefined2 extraout_var_00;
  int iVar6;
  uint uVar7;
  ezb_shortaddr_t aeStack_12 [3];
  
  aeStack_12[0] = dst_addr;
  if ((req == (aps_apsde_data_req_t *)0x0) || (pzVar2 = req->asdu, pzVar2 == (zmsg_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_main.c",0x275,
                  "apsde_data_request_continue","req != ((void *)0) && req->asdu != ((void *)0)");
  }
  else {
    _Var3 = aps_is_shortaddr_bcast(dst_addr);
    if (CONCAT31(extraout_var,_Var3) != 0) {
      aVar1 = req->field_9;
      req->field_9 = (anon_union_1_2_0b76fd53_for_aps_apsde_data_req_s_9)(aVar1.field_0 & 0xfb);
      req->field_9 = (anon_union_1_2_0b76fd53_for_aps_apsde_data_req_s_9)(aVar1.field_0 & 0xf9);
    }
    if (((byte)req->field_9 & 2) == 0) {
      req->field_9 = (anon_union_1_2_0b76fd53_for_aps_apsde_data_req_s_9)(req->field_9 & 0xfb);
    }
    uVar5 = zmsg_get_length(pzVar2);
    uVar7 = *(uint *)&req->field_9;
    uVar4 = aps_get_max_asdu((_Bool)((byte)(uVar7 >> 2) & 1),(_Bool)((byte)uVar7 & 1),
                             (_Bool)((byte)(uVar7 >> 3) & 1));
    if (uVar5 <= CONCAT22(extraout_var_00,uVar4)) {
      iVar6 = zmsg_add_footer(req->asdu,req,0x1c);
      if (iVar6 != 0) {
        return iVar6;
      }
      iVar6 = zmsg_add_footer(req->asdu,aeStack_12,2);
      if (iVar6 != 0) {
        return iVar6;
      }
      iVar6 = core_globals_get();
      zmsg_queue_enqueue(iVar6 + 0x2c,req->asdu);
      iVar6 = core_globals_get();
      tasklet_post(iVar6 + 0x1c);
      return 0;
    }
  }
  return 0x3a0;
}

