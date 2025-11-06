/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_commissioning.o -> esp_zcl_comm_restart_process_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010496) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_zcl_comm_restart_process_start(int param_1)

{
  void *__dest;
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_00010db0._2_1_ != '\0') {
    if (2 < (byte)(DAT_00010db0._2_1_ - 1U)) {
      uVar1 = esp_log_timestamp();
      esp_log(1,"ESP_ZIGBEE_ZCL_COMMISSIONING",
              "E (%lu) %s: Unsupported restart type(%d), abort the restart process\n",uVar1,
              "ESP_ZIGBEE_ZCL_COMMISSIONING",DAT_00010db0._2_1_);
      zb_buf_free_func(param_1);
      return;
    }
    iVar2 = zb_buf_get_tail_func(0xb);
    zb_get_long_address();
    *(undefined1 *)(iVar2 + 8) = DAT_000112d8;
    *(undefined1 *)(iVar2 + 9) = DAT_000112d9;
    *(byte *)(iVar2 + 10) = *(byte *)(iVar2 + 10) & 0x3f;
    zdo_mgmt_leave_req(param_1,esp_zcl_comm_restart_process_leave_done);
    return;
  }
  if (DAT_00010e08 == '\0') {
    _DAT_000112d8 = _g_comm_ctx;
    iVar2 = memcmp(&g_comm_ctx,&g_unknown_ieee_addr,8);
    if (iVar2 != 0) {
      zb_set_extended_pan_id(&g_comm_ctx);
    }
    _DAT_000112da = DAT_00010daa;
    zb_set_channel_mask(DAT_00010dac);
    iVar2 = memcmp(&g_comm_ctx,&g_zero_addr,8);
    if ((iVar2 == 0) || (iVar2 = memcmp(&g_comm_ctx,&g_unknown_ieee_addr,8), iVar2 == 0)) {
      zb_aib_set_trust_center_address(&g_comm_ctx);
    }
    iVar2 = memcmp(&g_comm_ctx,&g_zero_addr,8);
    if ((iVar2 != 0) || (iVar2 = memcmp(&g_comm_ctx,&g_zero_addr,8), iVar2 != 0)) {
      __dest = (void *)secur_nwk_key_by_seq(DAT_0001127f);
      if (__dest == (void *)0x0) {
        __dest = (void *)zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/zcl/esp_zigbee_zcl_commissioning.c"
                                   ,0x134);
      }
      memcpy(__dest,&DAT_00010dcb,0x10);
    }
    DAT_00011611 = DAT_00011611 & 0xfd | (byte)((DAT_00010ddb & 1) << 1);
    iVar2 = memcmp(&g_comm_ctx,&g_zero_addr,8);
    if ((iVar2 != 0) || (iVar2 = memcmp(&g_comm_ctx,&g_zero_addr,8), iVar2 != 0)) {
      memcpy((void *)0x1162c,&DAT_00010ddc,0x10);
      memcpy((void *)0x11640,&g_comm_ctx,0x10);
    }
    DAT_0001127f = DAT_00010dec;
    _DAT_00011288 = DAT_00010dee;
    zb_nwk_sync_pibcache_with_mac(param_1,esp_zcl_comm_restart_process_finish);
    return;
  }
  if (param_1 != 0) {
    zb_buf_free_func();
    return;
  }
  return;
}

