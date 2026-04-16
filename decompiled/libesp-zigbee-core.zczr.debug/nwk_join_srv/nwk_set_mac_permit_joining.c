/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_set_mac_permit_joining
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_set_mac_permit_joining(_Bool permitted)

{
  code *pcVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uStack_38;
  undefined4 uStack_34;
  code *pcStack_24;
  undefined1 auStack_11 [13];
  
  auStack_11[0] = permitted;
  iVar3 = nwk_mm_set_pib_attr(0xff,0x41,auStack_11);
  if (iVar3 == 0) {
    return;
  }
  pcVar1 = nwk_permit_joining_status_indication;
  uVar2 = __assert_func("//build/esp-zigbee/src/core/nwk/nwk_join_srv.c",0x47,
                        "nwk_set_mac_permit_joining",0x10000);
  uStack_34 = 0;
  uStack_38 = (uint)CONCAT12(uVar2,1);
  pcStack_24 = pcVar1;
  nwk_nlme_event_indication(&uStack_38);
  return;
}

