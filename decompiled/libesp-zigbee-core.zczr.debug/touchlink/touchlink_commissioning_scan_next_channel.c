/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_scan_next_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_commissioning_scan_next_channel(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  touchlink_commissioning_t *ptVar4;
  ezb_err_t eVar5;
  int iVar6;
  byte local_20 [4];
  uint8_t secondary_channel [12];
  uint8_t primary_channel [4];
  
  builtin_memcpy(secondary_channel + 8,"\v\x0f\x14\x19",4);
  local_20[0] = 0xc;
  local_20[1] = 0xd;
  local_20[2] = 0xe;
  local_20[3] = 0x10;
  builtin_memcpy(secondary_channel,"\x11\x12\x13\x15\x16\x17\x18\x1a",8);
  for (uVar1 = 0; uVar1 < 4; uVar1 = uVar1 + 1 & 0xff) {
    ptVar4 = touchlink_commissioning_get();
    uVar3 = (uint)secondary_channel[uVar1 + 8];
    if (((ptVar4->u).initiator.scan_channel_mask & 1 << (uVar3 & 0x1f)) != 0) {
      iVar6 = 0;
      goto _L0;
    }
  }
  ptVar4 = touchlink_commissioning_get();
  (ptVar4->u).initiator.scan_count = '\0';
  for (uVar1 = 0; uVar1 < 0xc; uVar1 = uVar1 + 1 & 0xff) {
    ptVar4 = touchlink_commissioning_get();
    uVar3 = (uint)secondary_channel[uVar1 - 4];
    if (((ptVar4->u).initiator.scan_channel_mask & 1 << (uVar3 & 0x1f)) != 0) goto _L0;
  }
  uVar3 = 0xb;
  iVar6 = 5;
_L0:
  if (iVar6 == 0) {
_L0:
    ptVar4 = touchlink_commissioning_get();
    if ((ptVar4->u).initiator.scan_count == '\0') {
      uVar2 = 1;
    }
    else {
      ptVar4 = touchlink_commissioning_get();
      if ((ptVar4->u).initiator.scan_count == '\x05') {
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    ptVar4 = touchlink_commissioning_get();
    if ((ptVar4->u).initiator.scan_count != '\0') {
      ptVar4 = touchlink_commissioning_get();
      (ptVar4->u).initiator.scan_count = (ptVar4->u).initiator.scan_count + 0xff;
    }
    ptVar4 = touchlink_commissioning_get();
    if ((ptVar4->u).initiator.scan_count == '\0') {
      ptVar4 = touchlink_commissioning_get();
      (ptVar4->u).initiator.scan_channel_mask =
           ~(1 << (uVar3 & 0x1f)) & (ptVar4->u).initiator.scan_channel_mask;
    }
    touchlink_set_intrp_channel(uVar3);
    ptVar4 = touchlink_commissioning_get();
    eVar5 = touchlink_send_scan_req(uVar2,(undefined1 *)((int)&ptVar4->u + 4));
  }
  else {
    ptVar4 = touchlink_commissioning_get();
    (ptVar4->u).initiator.scan_count = '\0';
    ptVar4 = touchlink_commissioning_get();
    (ptVar4->u).initiator.scan_channel_mask = 0;
    eVar5 = 5;
  }
  return eVar5;
}

