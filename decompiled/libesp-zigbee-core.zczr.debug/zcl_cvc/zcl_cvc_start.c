/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_cvc.o -> zcl_cvc_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_cvc_start(void *arg)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = milli_timer_get_now();
  if ((arg != (void *)0x0) && (*(code **)((int)arg + 0x34) != (code *)0x0)) {
    uVar5 = *(uint *)((int)arg + 0x14);
    uVar4 = *(uint *)((int)arg + 0x10);
    if (uVar5 <= uVar4) {
      if (uVar5 != 0) {
        iVar2 = *(int *)((int)arg + 0x30) + (int)*(char *)((int)arg + 1) * *(int *)((int)arg + 4);
        *(int *)((int)arg + 0x30) = iVar2;
        uVar3 = *(int *)((int)arg + 0xc) + *(int *)((int)arg + 8);
        *(uint *)((int)arg + 0xc) = uVar3;
        if (uVar4 <= uVar3) {
          *(int *)((int)arg + 0x30) = iVar2 + *(char *)((int)arg + 1);
          *(uint *)((int)arg + 0xc) = uVar3 - uVar4;
        }
      }
      if (*(char *)((int)arg + 0x2c) == '\x01') {
        *(undefined4 *)((int)arg + 0x14) = 1;
        iVar2 = 0xffff;
      }
      else {
        iVar2 = (*(uint *)((int)arg + 0x18) / 100) * (uVar4 - uVar5);
        *(uint *)((int)arg + 0x14) = uVar5 + 1;
      }
                    /* WARNING: Load size is inaccurate */
      (**(code **)((int)arg + 0x34))
                (*arg,*(undefined4 *)((int)arg + 0x30),iVar2,*(undefined4 *)((int)arg + 0x38));
      milli_timer_fire_at((int)arg + 0x1c,*(int *)((int)arg + 0x18) + iVar1);
    }
  }
  return;
}

