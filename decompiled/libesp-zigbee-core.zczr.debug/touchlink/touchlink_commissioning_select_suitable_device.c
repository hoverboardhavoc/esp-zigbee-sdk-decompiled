/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_select_suitable_device
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int touchlink_commissioning_select_suitable_device(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  
  bVar9 = 0;
  iVar7 = -0x80;
  iVar8 = 0;
  for (uVar1 = 0; iVar2 = touchlink_transaction_get(), uVar1 < *(byte *)(iVar2 + 8);
      uVar1 = uVar1 + 1 & 0xff) {
    iVar2 = touchlink_transaction_get();
    iVar6 = uVar1 * 0xc0 + iVar2;
    if ((((*(ushort *)(iVar6 + 0x14) & 3) == 1) || (iVar4 = touchlink_is_factory_new(), iVar4 == 0))
       || (((*(ushort *)(uVar1 * 0xc0 + iVar2 + 0x14) & 3) == 2 &&
           (uVar3 = touchlink_zigbee_info(), (uVar3 & 3) == 1)))) {
      iVar4 = uVar1 * 0xc0 + iVar2;
      iVar4 = (int)(((uint)*(byte *)(iVar4 + 0x1a) + (uint)*(byte *)(iVar4 + 200)) * 0x1000000) >>
              0x18;
      bVar5 = *(byte *)(iVar2 + uVar1 * 0xc0 + 0x16) & 1;
      if ((iVar7 < iVar4) && (bVar9 <= bVar5)) {
        iVar7 = iVar4;
        iVar8 = iVar6 + 0xc;
        bVar9 = bVar5;
      }
    }
  }
  if ((iVar8 == 0) || (iVar7 = touchlink_commissioning_action_permission(0,iVar8 + 0xf), iVar7 == 0)
     ) {
    iVar8 = 0;
  }
  return iVar8;
}

