/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_commissioning.o -> esp_zcl_comm_restart_process_install
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
  
  if (DAT_00010e08 == '\0') {
    _DAT_000112d8 = _g_comm_ctx;
    iVar1 = memcmp(&g_comm_ctx,&g_unknown_ieee_addr,8);
    if (iVar1 != 0) {
      zb_set_extended_pan_id(&g_comm_ctx);
    }
    _DAT_000112da = DAT_00010daa;
    zb_set_channel_mask(DAT_00010dac);
    iVar1 = memcmp(&g_comm_ctx,&g_zero_addr,8);
    if ((iVar1 == 0) || (iVar1 = memcmp(&g_comm_ctx,&g_unknown_ieee_addr,8), iVar1 == 0)) {
      zb_aib_set_trust_center_address(&g_comm_ctx);
    }
    iVar1 = memcmp(&g_comm_ctx,&g_zero_addr,8);
    if ((iVar1 != 0) || (iVar1 = memcmp(&g_comm_ctx,&g_zero_addr,8), iVar1 != 0)) {
      __dest = (void *)secur_nwk_key_by_seq(DAT_0001127f);
      if (__dest == (void *)0x0) {
        __dest = (void *)zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/zcl/esp_zigbee_zcl_commissioning.c"
                                   ,0x134);
      }
      memcpy(__dest,&DAT_00010dcb,0x10);
    }
    DAT_00011611 = DAT_00011611 & 0xfd | (byte)((DAT_00010ddb & 1) << 1);
    iVar1 = memcmp(&g_comm_ctx,&g_zero_addr,8);
    if ((iVar1 != 0) || (iVar1 = memcmp(&g_comm_ctx,&g_zero_addr,8), iVar1 != 0)) {
      memcpy((void *)0x1162c,&DAT_00010ddc,0x10);
      memcpy((void *)0x11640,&g_comm_ctx,0x10);
    }
    DAT_0001127f = DAT_00010dec;
    _DAT_00011288 = DAT_00010dee;
    zb_nwk_sync_pibcache_with_mac(param_1,UNRECOVERED_JUMPTABLE);
    return;
  }
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00010494. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}

