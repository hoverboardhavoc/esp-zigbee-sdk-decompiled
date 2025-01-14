/*
 * Last changed at upstream commit 5becf8b58fd0c6a13fec507be821364ad0ceba39
 * https://github.com/espressif/esp-zigbee-sdk/commit/5becf8b58fd0c6a13fec507be821364ad0ceba39
 * Upstream date: 2025-01-14 03:03:09 +0000
 * Upstream subject: esp-zigbee-sdk: (acad93d1)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_commissioning.o -> esp_zcl_comm_restart_process_leave_done
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
  if (DAT_00010e18 == '\0') {
    _DAT_000112d8 = g_comm_ctx;
    iVar2 = memcmp(&g_comm_ctx,&g_unknown_ieee_addr,8);
    if (iVar2 != 0) {
      zb_set_extended_pan_id(&g_comm_ctx);
    }
    _DAT_000112da = DAT_00010dba;
    zb_set_channel_mask(DAT_00010dbc);
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
      memcpy(__dest,&DAT_00010ddb,0x10);
    }
    DAT_00011611 = DAT_00011611 & 0xfd | (byte)((DAT_00010deb & 1) << 1);
    iVar2 = memcmp(&g_comm_ctx,&g_zero_addr,8);
    if ((iVar2 != 0) || (iVar2 = memcmp(&g_comm_ctx,&g_zero_addr,8), iVar2 != 0)) {
      memcpy((void *)0x1162c,&DAT_00010dec,0x10);
      memcpy((void *)0x11640,&g_comm_ctx,0x10);
    }
    DAT_0001127f = DAT_00010dfc;
    _DAT_00011288 = DAT_00010dfe;
    zb_nwk_sync_pibcache_with_mac(param_1,esp_zcl_commissioning_restart_process_rejoin);
    return;
  }
  uVar3 = 4;
  if ((char)g_comm_ctx != '\x01') {
    if ((char)g_comm_ctx == '\x02') {
      uVar3 = zb_buf_get_out_func();
      puVar1 = (undefined1 *)zb_buf_get_tail_func(1);
      *puVar1 = 0;
      zb_schedule_callback(&zdo_commissioning_initiate_rejoin,uVar3);
      goto _L0;
    }
    if ((char)g_comm_ctx != '\x03') goto _L0;
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

