/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> zcl_time_server_read_attr_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool zcl_time_server_read_attr_rsp_handler(zcl_cmd_read_attr_rsp_message_t *message)

{
  uint16_t short_address;
  ezb_zcl_read_attr_rsp_variable_t *peVar1;
  zcl_time_server_time_ctx_t *pzVar2;
  int iVar3;
  ezb_zcl_time_server_rank_t eVar4;
  uint uVar5;
  uint32_t uVar6;
  
  if (message == (zcl_cmd_read_attr_rsp_message_t *)0x0) {
    iVar3 = 0;
  }
  else if ((message->in).variables == (ezb_zcl_read_attr_rsp_variable_t *)0x0) {
    iVar3 = 0;
  }
  else {
    pzVar2 = time_server_get_time_ctx(((message->in).header)->dst_ep);
    if ((pzVar2 == (zcl_time_server_time_ctx_t *)0x0) ||
       (iVar3 = milli_timer_is_running(&pzVar2->sync_timer), iVar3 == 0)) {
      iVar3 = 0;
    }
    else {
      short_address = (((message->in).header)->src_addr).u.short_addr;
      eVar4 = EZB_ZCL_TIME_SERVER_RANK_UNSYNCHRONIZED;
      uVar6 = 0;
      for (peVar1 = (message->in).variables; peVar1 != (ezb_zcl_read_attr_rsp_variable_t *)0x0;
          peVar1 = peVar1->next) {
        uVar5._0_2_ = peVar1->attr_id;
        uVar5._2_1_ = peVar1->status;
        uVar5._3_1_ = peVar1->attr_type;
        if (((uVar5 & 0xffffff) == 0) && ((uint32_t *)peVar1->attr_value != (uint32_t *)0x0)) {
                    /* WARNING: Load size is inaccurate */
          uVar6 = *peVar1->attr_value;
        }
        else if (((uVar5 & 0xffffff) == 1) && ((uint8_t *)peVar1->attr_value != (uint8_t *)0x0)) {
                    /* WARNING: Load size is inaccurate */
          eVar4 = zcl_time_get_server_rank(*peVar1->attr_value,short_address);
        }
      }
      if ((uVar6 != 0xffffffff) &&
         ((pzVar2->min_rank < eVar4 ||
          ((pzVar2->min_rank == eVar4 && (short_address < pzVar2->server_addr)))))) {
        pzVar2->min_rank = (uint8_t)eVar4;
        pzVar2->server_addr = short_address;
        if (pzVar2->nwk_time != uVar6) {
          pzVar2->nwk_time = uVar6;
          (*(pzVar2->interface).set_utc_time)(uVar6);
        }
      }
    }
  }
  return SUB41(iVar3,0);
}

