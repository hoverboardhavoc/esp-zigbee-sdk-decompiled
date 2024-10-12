/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_commissioning.o -> esp_zcl_comm_restart_process_leave_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_zcl_comm_restart_process_leave_done(int param_1)

{
  undefined1 *puVar1;
  void *__dest;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = zb_buf_get_tail_func(2);
  if (*(char *)(iVar2 + 1) != '\0') {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_COMMISSIONING",&_L0,uVar3,"ESP_ZIGBEE_ZCL_COMMISSIONING",
                  *(undefined1 *)(iVar2 + 1));
    zb_buf_free_func(param_1);
    return;
  }
  if (DAT_00010e08 == '\0') {
    _DAT_000112e0 = _g_comm_ctx;
    iVar2 = memcmp(&g_comm_ctx,&g_unknown_ieee_addr,8);
    if (iVar2 != 0) {
      zb_set_extended_pan_id(&g_comm_ctx);
    }
    _DAT_000112e2 = DAT_00010daa;
    zb_set_channel_mask(DAT_00010dac);
    iVar2 = memcmp(&g_comm_ctx,&g_zero_addr,8);
    if ((iVar2 == 0) || (iVar2 = memcmp(&g_comm_ctx,&g_unknown_ieee_addr,8), iVar2 == 0)) {
      zb_aib_set_trust_center_address(&g_comm_ctx);
    }
    iVar2 = memcmp(&g_comm_ctx,&g_zero_addr,8);
    if ((iVar2 != 0) || (iVar2 = memcmp(&g_comm_ctx,&g_zero_addr,8), iVar2 != 0)) {
      __dest = (void *)secur_nwk_key_by_seq(DAT_00011281);
      if (__dest == (void *)0x0) {
        __dest = (void *)zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/zcl/esp_zigbee_zcl_commissioning.c"
                                   ,0x134);
      }
      memcpy(__dest,&DAT_00010dcb,0x10);
    }
    DAT_00011619 = DAT_00011619 & 0xfd | (byte)((DAT_00010ddb & 1) << 1);
    iVar2 = memcmp(&g_comm_ctx,&g_zero_addr,8);
    if ((iVar2 != 0) || (iVar2 = memcmp(&g_comm_ctx,&g_zero_addr,8), iVar2 != 0)) {
      memcpy((void *)0x11634,&DAT_00010ddc,0x10);
      memcpy((void *)0x11648,&g_comm_ctx,0x10);
    }
    DAT_00011281 = DAT_00010dec;
    _DAT_0001128c = DAT_00010dee;
    zb_nwk_sync_pibcache_with_mac(param_1,esp_zcl_commissioning_restart_process_rejoin);
    return;
  }
  uVar3 = 4;
  if (g_comm_ctx != '\x01') {
    if (g_comm_ctx == '\x02') {
      uVar3 = zb_buf_get_out_func();
      puVar1 = (undefined1 *)zb_buf_get_tail_func(1);
      *puVar1 = 0;
      zb_schedule_callback(&zdo_commissioning_initiate_rejoin,uVar3);
      goto _L0;
    }
    if (g_comm_ctx != '\x03') goto _L0;
    uVar3 = 0;
  }
  bdb_start_top_level_commissioning(uVar3);
_L0:
  if (param_1 == 0) {
    return;
  }
  zb_buf_free_func();
  return;
}

