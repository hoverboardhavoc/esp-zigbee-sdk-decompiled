/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> time.o -> zcl_time_server_read_attr_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool zcl_time_server_read_attr_rsp_handler(zcl_cmd_read_attr_rsp_message_t *message)

{
  byte bVar1;
  ushort uVar2;
  zcl_time_server_time_ctx_t *pzVar3;
  uint32_t uVar4;
  uint uVar5;
  ezb_zcl_read_attr_rsp_variable_t *peVar6;
  byte bVar7;
  _func_void_uint32_t *p_Var8;
  _Bool has_master;
  int iVar9;
  
  if ((((message == (zcl_cmd_read_attr_rsp_message_t *)0x0) ||
       ((message->in).variables == (ezb_zcl_read_attr_rsp_variable_t *)0x0)) ||
      (pzVar3 = time_server_get_time_ctx(((message->in).header)->dst_ep),
      pzVar3 == (zcl_time_server_time_ctx_t *)0x0)) ||
     (iVar9 = milli_timer_is_running(&pzVar3->sync_timer), iVar9 == 0)) {
    iVar9 = 0;
  }
  else {
    uVar2 = (((message->in).header)->src_addr).u.short_addr;
    uVar4 = 0;
    bVar7 = 0;
    for (peVar6 = (message->in).variables; peVar6 != (ezb_zcl_read_attr_rsp_variable_t *)0x0;
        peVar6 = peVar6->next) {
      uVar5._0_2_ = peVar6->attr_id;
      uVar5._2_1_ = peVar6->status;
      uVar5._3_1_ = peVar6->attr_type;
      if ((uVar5 & 0xffffff) == 0) {
        if ((uint32_t *)peVar6->attr_value != (uint32_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
          uVar4 = *peVar6->attr_value;
        }
      }
      else if (((uVar5 & 0xffffff) == 1) && ((byte *)peVar6->attr_value != (byte *)0x0)) {
                    /* WARNING: Load size is inaccurate */
        bVar1 = *peVar6->attr_value;
        if (uVar2 == 0) {
          if ((bVar1 & 8) == 0) {
_L0:
            bVar7 = 2;
            if ((bVar1 & 1) == 0) {
              bVar7 = bVar1 >> 1 & 1;
            }
          }
          else {
            bVar7 = 5;
            if ((bVar1 & 1) == 0) goto _L0;
          }
        }
        else {
          if ((bVar1 & 8) == 0) goto _L0;
_L0:
          bVar7 = (bVar1 & 1) + 3;
        }
      }
    }
    if ((uVar4 != 0xffffffff) &&
       ((pzVar3->min_rank < bVar7 || ((pzVar3->min_rank == bVar7 && (uVar2 < pzVar3->server_addr))))
       )) {
      pzVar3->min_rank = bVar7;
      pzVar3->server_addr = uVar2;
      if (pzVar3->nwk_time != uVar4) {
        p_Var8 = (pzVar3->interface).set_utc_time;
        pzVar3->nwk_time = uVar4;
        (*p_Var8)(uVar4);
      }
    }
  }
  return SUB41(iVar9,0);
}

