/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_discovery.o -> nwk_nlme_active_scan_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: nwk_scan_result */
/* WARNING: Unknown calling convention */

void nwk_nlme_active_scan_callback(active_scan_result_t *scan_result,void *user_ctx)

{
  int iVar1;
  int iVar2;
  uint8_t *puVar3;
  ezb_shortaddr_t eStack_24;
  ezb_panid_t eStack_22;
  ezb_nwk_active_scan_result_t nwk_scan_result;
  
  iVar1 = core_globals_get();
  if (*(code **)(iVar1 + 0xad0) != (code *)0x0) {
    if (scan_result == (active_scan_result_t *)0x0) {
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + 0xac0) = 0;
                    /* WARNING: Could not recover jumptable at 0x00010104. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(iVar1 + 0xad0))(0,user_ctx,*(code **)(iVar1 + 0xad0));
      return;
    }
    if ((scan_result->pan_descriptor).coord_addr.addr_mode == '\x02') {
      eStack_24 = (scan_result->pan_descriptor).coord_addr.u.short_addr;
      puVar3 = scan_result->beacon_payload;
      nwk_scan_result.channel_number = '\0';
      eStack_22 = (scan_result->pan_descriptor).coord_panid;
      nwk_scan_result.extpanid.field_0._4_1_ = (scan_result->pan_descriptor).channel_page;
      nwk_scan_result.extpanid.field_0._5_1_ = (scan_result->pan_descriptor).channel_number;
      nwk_scan_result.extpanid.field_0.u8[7] = puVar3[1] & 0xf | puVar3[1] & 0xf0;
      nwk_scan_result.channel_page =
           (byte)((scan_result->pan_descriptor).superframe_spec >> 0xf) | puVar3[2] >> 1 & 2 |
           (puVar3[2] >> 7) << 2;
      nwk_scan_result.extpanid.field_0.u8[6] = puVar3[0xe];
      nwk_scan_result._0_4_ = *(undefined4 *)(puVar3 + 3);
      nwk_scan_result.extpanid.field_0.u64._0_4_ = *(undefined4 *)(puVar3 + 7);
      (**(code **)(iVar1 + 0xad0))(&eStack_24);
    }
  }
  return;
}

