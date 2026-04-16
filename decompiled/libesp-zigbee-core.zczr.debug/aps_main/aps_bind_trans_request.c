/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_bind_trans_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_bind_trans_request(aps_apsde_data_req_t *req)

{
  int iVar1;
  ezb_err_t eVar2;
  aps_bind_src_t *local_20;
  aps_bind_ctx_t bind_ctx;
  
  if ((req == (aps_apsde_data_req_t *)0x0) || (req->asdu == (zmsg_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/aps/aps_main.c",0x14a,"aps_bind_trans_request",
                  "req != ((void *)0) && req->asdu != ((void *)0)");
  }
  else if ((req->dst_addr).addr_mode == '\0') {
    local_20 = (aps_bind_src_t *)0x0;
    bind_ctx.src = (aps_bind_src_t *)0x0;
    bind_ctx.dst = (aps_bind_dst_t *)0x0;
    bind_ctx.error = 0;
    nwk_get_extended_address();
    local_20 = (aps_bind_src_t *)aps_bind_table_find_src(req->src_ep,req->cluster_id);
    if (local_20 == (aps_bind_src_t *)0x0) {
      return 0x3a8;
    }
    iVar1 = zmsg_add_footer(req->asdu,req,0x1c);
    if (iVar1 != 0) {
      return iVar1;
    }
    goto _L0;
  }
  __assert_func("//build/esp-zigbee/src/core/aps/aps_main.c",0x14b,"aps_bind_trans_request",
                "req->dst_addr.addr_mode == EZB_ADDR_MODE_NONE");
_L0:
  eVar2 = aps_bind_trans_schedule_next_nmsg
                    (local_20,(aps_bind_dst_t *)bind_ctx.src,req->asdu,(uint8_t *)&bind_ctx.error);
  if (eVar2 == 0) {
    eVar2 = zmsg_add_footer(req->asdu,&local_20,0x10);
  }
  return eVar2;
}

