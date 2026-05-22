/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_apsde_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: dst_addr */
/* WARNING: Unknown calling convention */

ezb_err_t aps_apsde_data_request(aps_apsde_data_req_t *req)

{
  byte bVar1;
  ezb_shortaddr_t addr;
  aps_apsde_data_req_t *paVar2;
  _Bool _Var3;
  undefined3 extraout_var;
  int iVar4;
  undefined2 uStack_28;
  ezb_shortaddr_t eStack_26;
  zdo_nwk_addr_req_t zdo_req;
  ezb_shortaddr_t dst_addr;
  
  paVar2 = req;
  if (req == (aps_apsde_data_req_t *)0x0) {
_L0:
    iVar4 = 2;
    goto _L0;
  }
  paVar2 = (aps_apsde_data_req_t *)req->asdu;
  if (paVar2 == (aps_apsde_data_req_t *)0x0) {
    iVar4 = 2;
    goto _L0;
  }
  bVar1 = (req->dst_addr).addr_mode;
  if (bVar1 == 2) {
    addr = (req->dst_addr).u.short_addr;
_L0:
    zdo_req.user_ctx._2_2_ = addr;
    iVar4 = apsde_data_request_continue(req,zdo_req.user_ctx._2_2_);
  }
  else {
    if (2 < bVar1) {
      if (bVar1 != 3) {
        iVar4 = 2;
        goto _L0;
      }
      iVar4 = nwk_address_short_by_extended
                        (&(req->dst_addr).u,(undefined1 *)((int)&zdo_req.user_ctx + 2));
      addr = zdo_req.user_ctx._2_2_;
      if (iVar4 != 0) {
        zmsg_add_footer(paVar2,req,0x1c);
        zdo_req._0_4_ = *(undefined4 *)((int)&(req->dst_addr).u + 2);
        _uStack_28 = CONCAT22((req->dst_addr).u.short_addr,0xffff);
        zdo_req.field.ieee_addr_of_interest.field_0.u64._4_2_ = 0;
        zdo_req.field.ieee_addr_of_interest.field_0.u64._2_2_ =
             *(ushort *)((int)&(req->dst_addr).u + 6);
        zdo_req.field._6_4_ = apsde_handle_nwk_addr_req_result;
        zdo_req.cb = (ezb_zdo_nwk_addr_req_callback_t)paVar2;
        iVar4 = zdo_nwk_addr_req(&uStack_28);
        if (iVar4 == 0) {
          return 0;
        }
        iVar4 = 0x3a9;
        goto _L0;
      }
      goto _L0;
    }
    if (bVar1 != 0) {
      if (bVar1 != 1) {
        iVar4 = 2;
        goto _L0;
      }
      addr = (req->dst_addr).u.group_addr.bcast;
      _Var3 = aps_is_shortaddr_bcast(addr);
      if (CONCAT31(extraout_var,_Var3) == 0) {
        iVar4 = 2;
        goto _L0;
      }
      goto _L0;
    }
    if ((paVar2->alias_src_addr & 0x20) != 0) {
      paVar2 = (aps_apsde_data_req_t *)
               __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_main.c",0x2c3,
                             "aps_apsde_data_request",
                             "!zmsg_test_flag(msg, ((1 << ((5) % (sizeof(unsigned long) * 8)))))");
      goto _L0;
    }
    iVar4 = aps_bind_trans_request(req);
  }
  if (iVar4 == 0) {
    return 0;
  }
_L0:
  if (paVar2 != (aps_apsde_data_req_t *)0x0) {
    zmsg_free(paVar2);
  }
  return iVar4;
}

