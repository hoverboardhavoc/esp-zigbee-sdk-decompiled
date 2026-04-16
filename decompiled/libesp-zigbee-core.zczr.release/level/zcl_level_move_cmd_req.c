/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> level.o -> zcl_level_move_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_level_move_cmd_req(_Bool is_on_off,ezb_zcl_level_move_cmd_t *req)

{
  _Bool _Var1;
  undefined3 in_register_00002029;
  int iVar2;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  memset(auStack_38,0,0x28);
  if (req == (ezb_zcl_level_move_cmd_t *)0x0) {
    iVar2 = 2;
  }
  else {
    iVar2 = zcl_packet_init(auStack_38,0);
    if (iVar2 == 0) {
      _Var1 = (req->cmd_ctrl).dis_default_rsp;
      memcpy(auStack_50,req,10);
      iVar2 = zcl_cmd_to_packet(auStack_38,0,0,_Var1,0,
                                (-(uint)(CONCAT31(in_register_00002029,is_on_off) == 0) & 0xfffffffc
                                ) + 5,8);
      if ((((iVar2 == 0) &&
           (iVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,(req->payload).move_mode), iVar2 == 0))
          && (iVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,(req->payload).rate), iVar2 == 0)) &&
         ((iVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,(req->payload).options_mask), iVar2 == 0
          && (iVar2 = zmsg_append_u8((zmsg_t *)packet._32_4_,(req->payload).options_override),
             iVar2 == 0)))) {
        zcl_packet_send(auStack_38,&(req->cmd_ctrl).cnf_ctx);
        iVar2 = zcl_status_to_err();
        if (iVar2 == 0) {
          return 0;
        }
      }
    }
    else {
      iVar2 = -1;
    }
  }
  zcl_packet_free(auStack_38);
  return iVar2;
}

