/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_commissioning.o -> esp_zcl_comm_restart_process_install
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_zcl_comm_restart_process_install(undefined4 param_1,code *UNRECOVERED_JUMPTABLE)

{
  int iVar1;
  void *__dest;
  
  if (DAT_00010df8 == '\0') {
    _DAT_000112e0 = _g_comm_ctx;
    iVar1 = memcmp(&g_comm_ctx,&g_unknown_ieee_addr,8);
    if (iVar1 != 0) {
      esp_zb_set_extended_pan_id(&g_comm_ctx);
    }
    _DAT_000112e2 = DAT_00010d9a;
    esp_zb_set_channel_mask(DAT_00010d9c);
    iVar1 = memcmp(&g_comm_ctx,&g_zero_addr,8);
    if ((iVar1 == 0) || (iVar1 = memcmp(&g_comm_ctx,&g_unknown_ieee_addr,8), iVar1 == 0)) {
      zb_aib_set_trust_center_address(&g_comm_ctx);
    }
    iVar1 = memcmp(&g_comm_ctx,&g_zero_addr,8);
    if ((iVar1 != 0) || (iVar1 = memcmp(&g_comm_ctx,&g_zero_addr,8), iVar1 != 0)) {
      __dest = (void *)secur_nwk_key_by_seq(DAT_00011280);
      if (__dest == (void *)0x0) {
        __dest = (void *)zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/zcl/esp_zigbee_zcl_commissioning.c"
                                   ,0x134);
      }
      memcpy(__dest,&DAT_00010dbb,0x10);
    }
    DAT_00011619 = DAT_00011619 & 0xfd | (byte)((DAT_00010dcb & 1) << 1);
    iVar1 = memcmp(&g_comm_ctx,&g_zero_addr,8);
    if ((iVar1 != 0) || (iVar1 = memcmp(&g_comm_ctx,&g_zero_addr,8), iVar1 != 0)) {
      esp_zb_secur_TC_standard_preconfigure_key_set(&g_comm_ctx);
      esp_zb_secur_TC_standard_distributed_key_set(&g_comm_ctx);
    }
    DAT_00011280 = DAT_00010ddc;
    _DAT_0001128c = DAT_00010dde;
    zb_nwk_sync_pibcache_with_mac(param_1,UNRECOVERED_JUMPTABLE);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010482. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

