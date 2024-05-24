/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_commissioning.o -> esp_zcl_comm_restart_process_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_zcl_comm_restart_process_start(int param_1)

{
  void *__dest;
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_00010db0._2_1_ != '\0') {
    if ((byte)(DAT_00010db0._2_1_ - 1U) < 3) {
      iVar2 = zb_buf_get_tail_func(0xb);
      zb_get_long_address();
      *(undefined1 *)(iVar2 + 8) = DAT_000112e0;
      *(undefined1 *)(iVar2 + 9) = DAT_000112e1;
      *(byte *)(iVar2 + 10) = *(byte *)(iVar2 + 10) & 0x3f;
      zdo_mgmt_leave_req(param_1,esp_zcl_comm_restart_process_leave_done);
      return;
    }
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_COMMISSIONING",&_LC4,uVar1,"ESP_ZIGBEE_ZCL_COMMISSIONING",
                  DAT_00010db0._2_1_);
    zb_buf_free_func(param_1);
    return;
  }
  if (DAT_00010e08 != '\0') {
    if (param_1 == 0) {
      return;
    }
    zb_buf_free_func();
    return;
  }
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
    __dest = (void *)secur_nwk_key_by_seq(DAT_00011280);
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
  DAT_00011280 = DAT_00010dec;
  _DAT_0001128c = DAT_00010dee;
  zb_nwk_sync_pibcache_with_mac(param_1,esp_zcl_comm_restart_process_finish);
  return;
}

