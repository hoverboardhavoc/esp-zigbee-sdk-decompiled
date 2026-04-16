/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_discovery.o -> nwk_nlme_active_scan_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: nwk_scan_result */
/* WARNING: Unknown calling convention */

void nwk_nlme_active_scan_callback(active_scan_result_t *scan_result,void *user_ctx)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  uint8_t *puVar5;
  ezb_shortaddr_t eStack_24;
  ezb_panid_t eStack_22;
  ezb_nwk_active_scan_result_t nwk_scan_result;
  
  iVar3 = core_globals_get();
  if (*(code **)(iVar3 + 0xad0) != (code *)0x0) {
    if (scan_result == (active_scan_result_t *)0x0) {
      iVar4 = core_globals_get();
      *(undefined1 *)(iVar4 + 0xac0) = 0;
      (**(code **)(iVar3 + 0xad0))(0,user_ctx,*(code **)(iVar3 + 0xad0));
    }
    else if ((scan_result->pan_descriptor).coord_addr.addr_mode == '\x02') {
      puVar5 = scan_result->beacon_payload;
      _eStack_24 = CONCAT22((scan_result->pan_descriptor).coord_panid,
                            (scan_result->pan_descriptor).coord_addr.u.short_addr);
      uVar1 = (scan_result->pan_descriptor).channel_page;
      uVar2 = (scan_result->pan_descriptor).channel_number;
      nwk_scan_result.extpanid.field_0.u8[5] = uVar2;
      nwk_scan_result.extpanid.field_0.u8[4] = uVar1;
      nwk_scan_result.channel_number = '\0';
      nwk_scan_result.channel_page =
           (byte)((puVar5[2] >> 2 & 1) << 1) |
           (byte)((scan_result->pan_descriptor).superframe_spec >> 0xf) | (puVar5[2] >> 7) << 2;
      nwk_scan_result.extpanid.field_0.u8[6] = puVar5[0xe];
      nwk_scan_result.extpanid.field_0.u8[7] = puVar5[1] & 0xf | puVar5[1] & 0xf0;
      nwk_scan_result._0_4_ = *(undefined4 *)(puVar5 + 3);
      nwk_scan_result.extpanid.field_0.u64._0_4_ = *(undefined4 *)(puVar5 + 7);
      (**(code **)(iVar3 + 0xad0))(&eStack_24,user_ctx);
    }
  }
  return;
}

