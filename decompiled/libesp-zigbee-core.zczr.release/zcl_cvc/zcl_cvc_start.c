/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zcl_cvc.o -> zcl_cvc_start
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
  if ((arg != (void *)0x0) && (*(code **)((int)arg + 0x38) != (code *)0x0)) {
    uVar5 = *(uint *)((int)arg + 0x14);
    uVar3 = *(uint *)((int)arg + 0x10);
    if (uVar5 <= uVar3) {
      if (uVar5 == 0) {
        *(int *)((int)arg + 0x30) = iVar1;
      }
      else {
        iVar2 = (int)*(char *)((int)arg + 1) * *(int *)((int)arg + 4) + *(int *)((int)arg + 0x34);
        *(int *)((int)arg + 0x34) = iVar2;
        uVar4 = *(int *)((int)arg + 0xc) + *(int *)((int)arg + 8);
        *(uint *)((int)arg + 0xc) = uVar4;
        if (uVar3 <= uVar4) {
          *(int *)((int)arg + 0x34) = *(char *)((int)arg + 1) + iVar2;
          *(uint *)((int)arg + 0xc) = uVar4 - uVar3;
        }
      }
      uVar4 = *(uint *)((int)arg + 0x18);
      if (*(char *)((int)arg + 0x2c) == '\x01') {
        *(undefined4 *)((int)arg + 0x14) = 1;
        iVar1 = iVar1 + uVar4;
        iVar2 = 0xffff;
      }
      else {
        *(uint *)((int)arg + 0x14) = uVar5 + 1;
        iVar2 = (uVar4 / 100) * (uVar3 - uVar5);
        iVar1 = (uVar5 + 1) * uVar4 + *(int *)((int)arg + 0x30);
      }
                    /* WARNING: Load size is inaccurate */
      (**(code **)((int)arg + 0x38))
                (*arg,*(undefined4 *)((int)arg + 0x34),iVar2,*(undefined4 *)((int)arg + 0x3c));
      milli_timer_fire_at((int)arg + 0x1c,iVar1);
      return;
    }
  }
  return;
}

