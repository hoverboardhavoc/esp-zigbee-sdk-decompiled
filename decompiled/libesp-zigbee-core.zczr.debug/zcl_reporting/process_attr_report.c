/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> process_attr_report
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void process_attr_report(zcl_reporting_info_t *info)

{
  ushort min_interval;
  ushort max_interval;
  byte bVar1;
  uint uVar2;
  _Bool _Var3;
  int iVar4;
  int iVar5;
  undefined3 extraout_var;
  undefined4 *puVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar2 = 0x7fffffff;
  if (info == (zcl_reporting_info_t *)0x0) {
    return;
  }
  iVar4 = core_globals_get();
  if (*(char *)(iVar4 + 0xd84) == '\0') {
    return;
  }
  if (info->direction != '\0') {
    if ((info->u).send_info.min_interval != 0) {
      milli_timer_get_now();
    }
    if ((info->u).send_info.min_interval == 0) {
      (info->next_fire).val = 0x7fffffff;
    }
    else {
      iVar4 = milli_timer_get_now();
      (info->next_fire).val = (uint)(info->u).send_info.min_interval * 1000 + iVar4;
    }
    goto _L0;
  }
  min_interval = (info->u).send_info.min_interval;
  uVar10 = (uint)min_interval;
  max_interval = (info->u).send_info.max_interval;
  uVar9 = (uint)max_interval;
  _Var3 = reporting_is_allowed(min_interval,max_interval);
  if (CONCAT31(extraout_var,_Var3) != 0) {
    uVar8 = *(uint *)&info->cluster_role >> 8 & 0xf;
    if (uVar8 == 3) {
      if ((uVar9 != 0) || ((*(uint *)&info->cluster_role >> 0xc & 6) != 0)) {
        info->field_0x9 = info->field_0x9 & 0xf0 | 4;
        uVar10 = 0;
_L0:
        iVar4 = milli_timer_get_now();
        (info->next_fire).val = uVar10 * 1000 + iVar4;
        goto _L0;
      }
      info->field_0x9 = info->field_0x9 & 0xf0;
    }
    else {
      if (3 < uVar8) goto _L0;
      if (uVar8 == 1) {
        if (uVar10 == 0) {
          info->field_0x9 = info->field_0x9 & 0xf0 | 3;
          uVar10 = uVar9;
        }
        else {
          info->field_0x9 = info->field_0x9 & 0xf0 | 2;
        }
_L0:
        if (uVar10 != 0xffff) goto _L0;
      }
      else if (uVar8 == 2) {
        if ((*(uint *)&info->cluster_role >> 0xc & 2) != 0) {
          info->field_0x9 = info->field_0x9 & 0xf0 | 3;
          uVar10 = 0;
          goto _L0;
        }
        if (uVar10 <= uVar9) {
          info->field_0x9 = info->field_0x9 & 0xf0 | 3;
          uVar10 = uVar9 - uVar10 & 0xffff;
          goto _L0;
        }
        info->field_0x9 = info->field_0x9 & 0xf0;
      }
      else if (uVar8 != 0) {
        do {
          __assert_func("//build/esp-zigbee/src/core/zcl/zcl_reporting.c",0x126,
                        "process_attr_report",&_L0);
_L0:
          if (uVar8 == 4) {
            zcl_report_attr_now(info);
            uVar10 = *(uint *)&info->cluster_role >> 0xc;
            bVar1 = info->field_0x9 & 0xf;
            info->field_0x9 = bVar1 | (byte)((uVar10 & 0xb) << 4);
            info->field_0x9 = (byte)((uVar10 & 9) << 4) | bVar1;
            break;
          }
        } while (uVar8 != 5);
      }
    }
  }
  (info->next_fire).val = 0x7fffffff;
_L0:
  iVar5 = core_globals_get();
  iVar4 = 0;
  for (puVar6 = *(undefined4 **)(iVar5 + 0xd98); piVar7 = puVar6 + -1, piVar7 != (int *)0xfffffffc;
      puVar6 = (undefined4 *)*puVar6) {
    if (((piVar7 != (int *)0x0) && (iVar5 = *piVar7, iVar5 != 0)) &&
       (*(uint *)(iVar5 + 0xc) < uVar2)) {
      uVar2 = *(uint *)(iVar5 + 0xc);
      iVar4 = iVar5;
    }
  }
  if (uVar2 < 0x7fffffff) {
    iVar5 = core_globals_get();
    milli_timer_stop(iVar5 + 0xd88);
    iVar5 = core_globals_get();
    milli_timer_init(iVar5 + 0xd88,process_attr_report,iVar4);
    iVar4 = core_globals_get();
    milli_timer_fire_at(iVar4 + 0xd88,uVar2);
  }
  return;
}

