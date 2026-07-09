/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> process_attr_report
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void process_attr_report(char *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  byte bVar8;
  int *piVar9;
  
  if (param_1 == (char *)0x0) {
    return;
  }
  iVar2 = core_globals_get();
  if (*(char *)(iVar2 + 0xd20) == '\0') {
    return;
  }
  uVar5 = (uint)*(ushort *)(param_1 + 0x10);
  if (*param_1 == '\0') {
    uVar1 = (uint)*(ushort *)(param_1 + 0x12);
    if (((uVar5 == 0) || (uVar5 != 0xffff)) && (uVar1 != 0xffff)) {
      uVar4 = *(uint *)(param_1 + 8);
      bVar8 = 3;
      bVar7 = 3;
      uVar6 = uVar4 >> 8 & 0xf;
      if (uVar6 == 3) {
        if ((uVar1 != 0) || ((uVar4 >> 0xc & 6) != 0)) {
          bVar7 = 4;
_L0:
          uVar1 = 0;
          param_1[9] = bVar7 | param_1[9] & 0xf0U;
_L0:
          iVar2 = milli_timer_get_now();
          goto _L0;
        }
_L0:
        bVar8 = param_1[9] & 0xf0;
_L0:
        param_1[9] = bVar8;
      }
      else if (uVar6 < 4) {
        if (uVar6 == 1) {
_L0:
          if (uVar5 != 0) {
            bVar8 = 2;
            uVar1 = uVar5;
          }
          param_1[9] = bVar8 | param_1[9] & 0xf0U;
          goto _L0;
        }
        if (uVar6 == 2) {
          if ((int)(uVar4 << 0x12) < 0) goto _L0;
          if (uVar1 < uVar5) goto _L0;
          param_1[9] = param_1[9] & 0xf0U | 3;
          uVar1 = uVar1 - uVar5 & 0xffff;
          if (uVar1 != 0xffff) goto _L0;
        }
      }
      else {
        if (uVar6 == 4) {
          zcl_report_attr_now(param_1);
          bVar8 = param_1[9] & 0xfU | (byte)((uint)*(undefined4 *)(param_1 + 8) >> 8) & 0x90;
          goto _L0;
        }
        bVar8 = 5;
        if (uVar6 != 5) {
          uVar5 = 0;
          __assert_func(0,0,0);
          goto _L0;
        }
      }
    }
  }
  else if ((uVar5 != 0) && (milli_timer_get_now(), *(short *)(param_1 + 0x10) != 0)) {
    iVar2 = milli_timer_get_now();
    uVar1 = (uint)*(ushort *)(param_1 + 0x10);
_L0:
    iVar2 = uVar1 * 1000 + iVar2;
    goto _L0;
  }
  iVar2 = 0x7fffffff;
_L0:
  *(int *)(param_1 + 0xc) = iVar2;
  iVar3 = core_globals_get();
  uVar5 = 0x7fffffff;
  iVar2 = 0;
  for (piVar9 = *(int **)(iVar3 + 0xd34); piVar9 + -1 != (int *)0xfffffffc; piVar9 = (int *)*piVar9)
  {
    iVar3 = piVar9[-1];
    if ((iVar3 != 0) && (*(uint *)(iVar3 + 0xc) < uVar5)) {
      uVar5 = *(uint *)(iVar3 + 0xc);
      iVar2 = iVar3;
    }
  }
  if (0x7ffffffe < uVar5) {
    return;
  }
  iVar3 = core_globals_get();
  milli_timer_stop(iVar3 + 0xd24);
  iVar3 = core_globals_get();
  milli_timer_init(iVar3 + 0xd24,process_attr_report,iVar2);
  iVar2 = core_globals_get();
  milli_timer_fire_at(iVar2 + 0xd24,uVar5);
  return;
}

