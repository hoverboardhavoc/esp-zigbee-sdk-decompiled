/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_comm_restart_process_install
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_zcl_comm_restart_process_install(undefined4 param_1,code *param_2)

{
  int iVar1;
  void *__dest;
  
  if (DAT_000117e8 == '\0') {
    _DAT_000122e0 = g_comm_ctx;
    iVar1 = memcmp(&g_comm_ctx,&g_unknown_ieee_addr,8);
    if (iVar1 != 0) {
      esp_zb_set_extended_pan_id(&g_comm_ctx);
    }
    _DAT_000122e2 = DAT_0001178a;
    esp_zb_set_channel_mask(DAT_0001178c);
    iVar1 = memcmp(&g_comm_ctx,&g_zero_addr,8);
    if ((iVar1 == 0) || (iVar1 = memcmp(&g_comm_ctx,&g_unknown_ieee_addr,8), iVar1 == 0)) {
      zb_aib_set_trust_center_address(&g_comm_ctx);
    }
    iVar1 = memcmp(&g_comm_ctx,&g_zero_addr,8);
    if ((iVar1 != 0) || (iVar1 = memcmp(&g_comm_ctx,&g_zero_addr,8), iVar1 != 0)) {
      __dest = (void *)secur_nwk_key_by_seq(DAT_00012280);
      if (__dest == (void *)0x0) {
        param_2 = (code *)zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/zcl/esp_zigbee_zcl_commissioning.c"
                                    ,0x134);
        goto _L0;
      }
      memcpy(__dest,&DAT_000117ab,0x10);
    }
    DAT_00012619 = DAT_00012619 & 0xfd | (byte)((DAT_000117bb & 1) << 1);
    iVar1 = memcmp(&g_comm_ctx,&g_zero_addr,8);
    if ((iVar1 != 0) || (iVar1 = memcmp(&g_comm_ctx,&g_zero_addr,8), iVar1 != 0)) {
      esp_zb_secur_TC_standard_preconfigure_key_set(&g_comm_ctx);
      esp_zb_secur_TC_standard_distributed_key_set(&g_comm_ctx);
    }
    DAT_00012280 = DAT_000117cc;
    _DAT_0001228c = DAT_000117ce;
    zb_nwk_sync_pibcache_with_mac(param_1,param_2);
  }
  else {
_L0:
    if (param_2 != (code *)0x0) {
      (*param_2)();
    }
  }
  return;
}

