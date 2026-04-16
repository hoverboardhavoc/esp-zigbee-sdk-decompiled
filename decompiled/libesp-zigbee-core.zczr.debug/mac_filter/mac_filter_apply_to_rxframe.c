/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac_filter.o -> mac_filter_apply_to_rxframe
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: extaddr */
/* WARNING: Unknown calling convention */

ezb_err_t mac_filter_apply_to_rxframe(mac_frame_t *frame)

{
  ezb_addr_mode_t eVar1;
  ezb_err_t unaff_s1;
  uint8_t uVar2;
  int iVar3;
  ezb_radio_frame_t *peVar4;
  uint8_t uStack_19;
  undefined1 auStack_18 [3];
  uint8_t fixed_lqa;
  ezb_extaddr_t extaddr;
  
  _auStack_18 = (frame->mhr).src_addr.u.group_addr;
  extaddr.field_0.u64._0_4_ = *(undefined4 *)((int)&(frame->mhr).src_addr.u + 4);
  uStack_19 = '\0';
  eVar1 = (frame->mhr).src_addr.addr_mode;
  if (eVar1 == '\x02') {
    iVar3 = nwk_address_extended_by_short((frame->mhr).src_addr.u.short_addr,auStack_18);
    if (iVar3 != 0) {
      return 0;
    }
_L0:
    unaff_s1 = mac_filter_apply((ezb_extaddr_t *)auStack_18,&uStack_19);
    if (unaff_s1 != 0) {
      return unaff_s1;
    }
  }
  else {
    if (eVar1 == '\x03') goto _L0;
    if (eVar1 != '\0') {
      __assert_func("//build/esp-zigbee/src/core/mac/mac_filter.c",0x107,
                    "mac_filter_apply_to_rxframe",&_LC0);
      goto _L0;
    }
    if (s_restrict_addressless) {
      return 0x12;
    }
    unaff_s1 = 0;
  }
  if (uStack_19 == '\0') {
    return unaff_s1;
  }
_L0:
  peVar4 = frame->from;
  uVar2 = nwk_lqa_to_lqi();
  (peVar4->info).tx.max_csma_backoffs = uVar2;
  peVar4 = frame->from;
  uVar2 = nwk_lqa_to_rssi(uStack_19);
  (peVar4->info).tx.max_frame_retries = uVar2;
  return unaff_s1;
}

