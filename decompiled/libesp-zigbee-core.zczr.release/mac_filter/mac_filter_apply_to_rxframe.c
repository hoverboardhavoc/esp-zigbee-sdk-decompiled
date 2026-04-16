/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac_filter.o -> mac_filter_apply_to_rxframe
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: extaddr */
/* WARNING: Unknown calling convention */

ezb_err_t mac_filter_apply_to_rxframe(mac_frame_t *frame)

{
  ezb_radio_frame_t *peVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  int iVar4;
  mac_filter_entry_t *pmVar5;
  uint uVar6;
  ezb_radio_frame_t *peVar7;
  undefined1 auStack_18 [4];
  ezb_extaddr_t extaddr;
  
  auStack_18 = *(undefined1 (*) [4])&(frame->mhr).src_addr.u.group_addr;
  extaddr.field_0.u64._0_4_ = *(undefined4 *)((int)&(frame->mhr).src_addr.u + 4);
  uVar6 = (uint)(frame->mhr).src_addr.addr_mode;
  if (uVar6 == 2) {
    iVar4 = nwk_address_extended_by_short((frame->mhr).src_addr.u.short_addr,auStack_18);
    if (iVar4 != 0) {
      return 0;
    }
_L0:
    pmVar5 = mac_filter_find_entry((ezb_extaddr_t *)auStack_18);
    uVar6 = 0;
    if (pmVar5 != (mac_filter_entry_t *)0x0) {
      uVar6 = (uint)pmVar5->filtered;
    }
    if (s_filter_mode != '\x01') {
      if (s_filter_mode == '\x02') {
        if (uVar6 != 0) {
          return 0x12;
        }
        goto _L0;
      }
      if (s_filter_mode == '\0') goto _L0;
      goto _L0;
    }
  }
  else {
    if (uVar6 == 3) goto _L0;
    if (uVar6 == 0) {
      if (s_restrict_addressless) {
        return 0x12;
      }
      return 0;
    }
_L0:
    pmVar5 = (mac_filter_entry_t *)__assert_func(0,0,0,0);
  }
  if (uVar6 == 0) {
    return 0x12;
  }
_L0:
  if ((pmVar5 != (mac_filter_entry_t *)0x0) && (uVar3 = pmVar5->lqa, uVar3 != '\0')) {
    peVar7 = frame->from;
    uVar2 = nwk_lqa_to_lqi(uVar3);
    peVar1 = frame->from;
    (peVar7->info).tx.max_csma_backoffs = uVar2;
    uVar3 = nwk_lqa_to_rssi(uVar3);
    (peVar1->info).tx.max_frame_retries = uVar3;
  }
  return 0;
}

