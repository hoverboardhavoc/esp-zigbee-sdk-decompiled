/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_mark_recv_attr_report
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_reporting_mark_recv_attr_report(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  byte bVar9;
  int *piVar10;
  
  pcVar4 = (char *)zcl_reporting_info_find();
  if (((pcVar4 == (char *)0x0) || (*pcVar4 != '\x01')) || (*(short *)(pcVar4 + 0x10) == 0)) {
    return;
  }
  if (pcVar4 == (char *)0x0) {
    return;
  }
  iVar2 = core_globals_get();
  if (*(char *)(iVar2 + 0xd20) == '\0') {
    return;
  }
  uVar6 = (uint)*(ushort *)(pcVar4 + 0x10);
  if (*pcVar4 == '\0') {
    uVar1 = (uint)*(ushort *)(pcVar4 + 0x12);
    if (((uVar6 == 0) || (uVar6 != 0xffff)) && (uVar1 != 0xffff)) {
      uVar5 = *(uint *)(pcVar4 + 8);
      bVar9 = 3;
      bVar8 = 3;
      uVar7 = uVar5 >> 8 & 0xf;
      if (uVar7 == 3) {
        if ((uVar1 != 0) || ((uVar5 >> 0xc & 6) != 0)) {
          bVar8 = 4;
_L0:
          uVar1 = 0;
          pcVar4[9] = bVar8 | pcVar4[9] & 0xf0U;
_L0:
          iVar2 = milli_timer_get_now();
          goto _L0;
        }
_L0:
        bVar9 = pcVar4[9] & 0xf0;
_L0:
        pcVar4[9] = bVar9;
      }
      else if (uVar7 < 4) {
        if (uVar7 == 1) {
_L0:
          if (uVar6 != 0) {
            bVar9 = 2;
            uVar1 = uVar6;
          }
          pcVar4[9] = bVar9 | pcVar4[9] & 0xf0U;
          goto _L0;
        }
        if (uVar7 == 2) {
          if ((int)(uVar5 << 0x12) < 0) goto _L0;
          if (uVar1 < uVar6) goto _L0;
          pcVar4[9] = pcVar4[9] & 0xf0U | 3;
          uVar1 = uVar1 - uVar6 & 0xffff;
          if (uVar1 != 0xffff) goto _L0;
        }
      }
      else {
        if (uVar7 == 4) {
          zcl_report_attr_now(pcVar4);
          bVar9 = pcVar4[9] & 0xfU | (byte)((uint)*(undefined4 *)(pcVar4 + 8) >> 8) & 0x90;
          goto _L0;
        }
        bVar9 = 5;
        if (uVar7 != 5) {
          uVar6 = 0;
          __assert_func(0,0,0);
          goto _L0;
        }
      }
    }
  }
  else if ((uVar6 != 0) && (milli_timer_get_now(), *(short *)(pcVar4 + 0x10) != 0)) {
    iVar2 = milli_timer_get_now();
    uVar1 = (uint)*(ushort *)(pcVar4 + 0x10);
_L0:
    iVar2 = uVar1 * 1000 + iVar2;
    goto _L0;
  }
  iVar2 = 0x7fffffff;
_L0:
  *(int *)(pcVar4 + 0xc) = iVar2;
  iVar3 = core_globals_get();
  uVar6 = 0x7fffffff;
  iVar2 = 0;
  for (piVar10 = *(int **)(iVar3 + 0xd34); piVar10 + -1 != (int *)0xfffffffc;
      piVar10 = (int *)*piVar10) {
    iVar3 = piVar10[-1];
    if ((iVar3 != 0) && (*(uint *)(iVar3 + 0xc) < uVar6)) {
      uVar6 = *(uint *)(iVar3 + 0xc);
      iVar2 = iVar3;
    }
  }
  if (0x7ffffffe < uVar6) {
    return;
  }
  iVar3 = core_globals_get();
  milli_timer_stop(iVar3 + 0xd24);
  iVar3 = core_globals_get();
  milli_timer_init(iVar3 + 0xd24,process_attr_report,iVar2);
  iVar2 = core_globals_get();
  milli_timer_fire_at(iVar2 + 0xd24,uVar6);
  return;
}

