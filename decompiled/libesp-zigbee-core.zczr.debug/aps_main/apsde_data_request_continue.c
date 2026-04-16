/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> apsde_data_request_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t apsde_data_request_continue(aps_apsde_data_req_t *req,ezb_shortaddr_t dst_addr)

{
  byte bVar1;
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
    __assert_func("//build/esp-zigbee/src/core/aps/aps_main.c",0x261,"apsde_data_request_continue",
                  "req != ((void *)0) && req->asdu != ((void *)0)");
  }
  else {
    _Var3 = aps_is_shortaddr_bcast(dst_addr);
    if (CONCAT31(extraout_var,_Var3) != 0) {
      bVar1 = req->field_0x18;
      req->field_0x18 = bVar1 & 0xfb;
      req->field_0x18 = bVar1 & 0xf9;
    }
    if ((req->field_0x18 & 2) == 0) {
      req->field_0x18 = req->field_0x18 & 0xfb;
    }
    uVar5 = zmsg_get_length(pzVar2);
    uVar7 = *(uint *)&req->field_0x18;
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

