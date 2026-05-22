/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> start_csma
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void start_csma(void)

{
  byte bVar1;
  uint8_t uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  bVar1 = ((s_mac_pal_ctx.tx_frame)->info).tx.min_csma_be;
  uVar5 = (uint)((s_mac_pal_ctx.tx_frame)->info).tx.max_csma_be;
  uVar2 = ((s_mac_pal_ctx.tx_frame)->info).tx.max_csma_backoffs;
  uVar3 = (uint)s_mac_pal_ctx.csma_nb;
  set_state(MAC_PAL_STATE_CSMA_BACKOFF);
  if (((s_mac_pal_ctx.radio_caps & 4) == 0) && (uVar2 != '\0')) {
    uVar3 = uVar3 + bVar1 & 0xff;
    if (uVar3 < uVar5) {
      uVar5 = uVar3;
    }
    iVar4 = random_noncrypto_range_u32(0,1 << (uVar5 & 0x1f));
    if ((s_mac_pal_ctx._3_1_ & 1) == 0) {
      ezb_plat_radio_sleep();
    }
    else {
      ezb_plat_radio_receive((s_mac_pal_ctx.tx_frame)->channel);
    }
    micro_timer_start(&s_mac_pal_ctx,iVar4 * 0x140);
    return;
  }
  start_transmit();
  return;
}

