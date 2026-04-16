/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> process_attr_report
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void process_attr_report(zcl_reporting_info_t *info)

{
  uint uVar1;
  uint32_t uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  byte bVar9;
  int *piVar10;
  
  if (info == (zcl_reporting_info_t *)0x0) {
    return;
  }
  iVar3 = core_globals_get();
  if (*(char *)(iVar3 + 0xd84) == '\0') {
    return;
  }
  uVar6 = (uint)(info->u).send_info.min_interval;
  if (info->direction == '\0') {
    uVar1 = (uint)(info->u).send_info.max_interval;
    if (((uVar6 == 0) || (uVar6 != 0xffff)) && (uVar1 != 0xffff)) {
      uVar5 = *(uint *)&info->cluster_role;
      bVar9 = 3;
      bVar8 = 3;
      uVar7 = uVar5 >> 8 & 0xf;
      if (uVar7 == 3) {
        if ((uVar1 != 0) || ((uVar5 >> 0xc & 6) != 0)) {
          bVar8 = 4;
_L0:
          uVar1 = 0;
          info->field_0x9 = bVar8 | info->field_0x9 & 0xf0;
_L0:
          iVar3 = milli_timer_get_now();
          goto _L0;
        }
_L0:
        bVar9 = info->field_0x9 & 0xf0;
_L0:
        info->field_0x9 = bVar9;
      }
      else if (uVar7 < 4) {
        if (uVar7 == 1) {
_L0:
          if (uVar6 != 0) {
            bVar9 = 2;
            uVar1 = uVar6;
          }
          info->field_0x9 = bVar9 | info->field_0x9 & 0xf0;
          goto _L0;
        }
        if (uVar7 == 2) {
          if ((int)(uVar5 << 0x12) < 0) goto _L0;
          if (uVar1 < uVar6) goto _L0;
          info->field_0x9 = info->field_0x9 & 0xf0 | 3;
          uVar1 = uVar1 - uVar6 & 0xffff;
          if (uVar1 != 0xffff) goto _L0;
        }
      }
      else {
        if (uVar7 == 4) {
          zcl_report_attr_now(info);
          bVar9 = info->field_0x9 & 0xf |
                  (byte)((uint)*(undefined4 *)&info->cluster_role >> 8) & 0x90;
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
  else if ((uVar6 != 0) && (milli_timer_get_now(), (info->u).send_info.min_interval != 0)) {
    iVar3 = milli_timer_get_now();
    uVar1 = (uint)(info->u).send_info.min_interval;
_L0:
    uVar2 = uVar1 * 1000 + iVar3;
    goto _L0;
  }
  uVar2 = 0x7fffffff;
_L0:
  (info->next_fire).val = uVar2;
  iVar4 = core_globals_get();
  uVar6 = 0x7fffffff;
  iVar3 = 0;
  for (piVar10 = *(int **)(iVar4 + 0xd98); piVar10 + -1 != (int *)0xfffffffc;
      piVar10 = (int *)*piVar10) {
    iVar4 = piVar10[-1];
    if ((iVar4 != 0) && (*(uint *)(iVar4 + 0xc) < uVar6)) {
      uVar6 = *(uint *)(iVar4 + 0xc);
      iVar3 = iVar4;
    }
  }
  if (0x7ffffffe < uVar6) {
    return;
  }
  iVar4 = core_globals_get();
  milli_timer_stop(iVar4 + 0xd88);
  iVar4 = core_globals_get();
  milli_timer_init(iVar4 + 0xd88,process_attr_report,iVar3);
  iVar3 = core_globals_get();
  milli_timer_fire_at(iVar3 + 0xd88,uVar6);
  return;
}

