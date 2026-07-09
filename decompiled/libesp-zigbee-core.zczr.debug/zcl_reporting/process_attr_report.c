/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> process_attr_report
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void process_attr_report(char *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar2 = 0x7fffffff;
  if (param_1 == (char *)0x0) {
    return;
  }
  iVar3 = core_globals_get();
  if (*(char *)(iVar3 + 0xd20) == '\0') {
    return;
  }
  if (*param_1 != '\0') {
    if (*(short *)(param_1 + 0x10) != 0) {
      milli_timer_get_now();
    }
    if (*(short *)(param_1 + 0x10) == 0) {
      param_1[0xc] = -1;
      param_1[0xd] = -1;
      param_1[0xe] = -1;
      param_1[0xf] = '\x7f';
    }
    else {
      iVar3 = milli_timer_get_now();
      *(uint *)(param_1 + 0xc) = (uint)*(ushort *)(param_1 + 0x10) * 1000 + iVar3;
    }
    goto _L0;
  }
  uVar9 = (uint)*(ushort *)(param_1 + 0x10);
  uVar8 = (uint)*(ushort *)(param_1 + 0x12);
  iVar3 = reporting_is_allowed(uVar9,uVar8);
  if (iVar3 != 0) {
    uVar7 = *(uint *)(param_1 + 8) >> 8 & 0xf;
    if (uVar7 == 3) {
      if ((uVar8 != 0) || ((*(uint *)(param_1 + 8) >> 0xc & 6) != 0)) {
        param_1[9] = param_1[9] & 0xf0U | 4;
        uVar9 = 0;
_L0:
        iVar3 = milli_timer_get_now();
        *(uint *)(param_1 + 0xc) = uVar9 * 1000 + iVar3;
        goto _L0;
      }
      param_1[9] = param_1[9] & 0xf0;
    }
    else {
      if (3 < uVar7) goto _L0;
      if (uVar7 == 1) {
        if (uVar9 == 0) {
          param_1[9] = param_1[9] & 0xf0U | 3;
          uVar9 = uVar8;
        }
        else {
          param_1[9] = param_1[9] & 0xf0U | 2;
        }
_L0:
        if (uVar9 != 0xffff) goto _L0;
      }
      else if (uVar7 == 2) {
        if ((*(uint *)(param_1 + 8) >> 0xc & 2) != 0) {
          param_1[9] = param_1[9] & 0xf0U | 3;
          uVar9 = 0;
          goto _L0;
        }
        if (uVar9 <= uVar8) {
          param_1[9] = param_1[9] & 0xf0U | 3;
          uVar9 = uVar8 - uVar9 & 0xffff;
          goto _L0;
        }
        param_1[9] = param_1[9] & 0xf0;
      }
      else if (uVar7 != 0) {
        do {
          __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_reporting.c",0x126,
                        "process_attr_report",&_L0);
_L0:
          if (uVar7 == 4) {
            zcl_report_attr_now(param_1);
            bVar1 = param_1[9];
            param_1[9] = bVar1 & 0xf | (byte)((*(uint *)(param_1 + 8) >> 0xc & 0xb) << 4);
            param_1[9] = (byte)((*(uint *)(param_1 + 8) >> 0xc & 9) << 4) | bVar1 & 0xf;
            break;
          }
        } while (uVar7 != 5);
      }
    }
  }
  param_1[0xc] = -1;
  param_1[0xd] = -1;
  param_1[0xe] = -1;
  param_1[0xf] = '\x7f';
_L0:
  iVar4 = core_globals_get();
  iVar3 = 0;
  for (puVar5 = *(undefined4 **)(iVar4 + 0xd34); piVar6 = puVar5 + -1, piVar6 != (int *)0xfffffffc;
      puVar5 = (undefined4 *)*puVar5) {
    if (((piVar6 != (int *)0x0) && (iVar4 = *piVar6, iVar4 != 0)) &&
       (*(uint *)(iVar4 + 0xc) < uVar2)) {
      uVar2 = *(uint *)(iVar4 + 0xc);
      iVar3 = iVar4;
    }
  }
  if (uVar2 < 0x7fffffff) {
    iVar4 = core_globals_get();
    milli_timer_stop(iVar4 + 0xd24);
    iVar4 = core_globals_get();
    milli_timer_init(iVar4 + 0xd24,process_attr_report,iVar3);
    iVar3 = core_globals_get();
    milli_timer_fire_at(iVar3 + 0xd24,uVar2);
  }
  return;
}

