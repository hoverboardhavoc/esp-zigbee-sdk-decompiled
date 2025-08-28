/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_alarms.o -> zb_zcl_alarms_alarm_table_add_log
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zb_zcl_alarms_alarm_table_add_log(undefined4 param_1,undefined1 param_2,undefined2 param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  
  zb_af_get_endpoint_desc();
  iVar2 = get_cluster_desc(10,1);
  uVar7 = 0xffffffff;
  if (iVar2 != 0) {
    iVar2 = zb_zcl_get_attr_desc(0);
    uVar7 = **(undefined4 **)(iVar2 + 6);
  }
  puVar3 = (undefined4 *)alarms_get_alarm_table(param_1);
  if (puVar3 == (undefined4 *)0x0) {
_L0:
    uVar7 = 0x105;
  }
  else {
    iVar2 = zb_zcl_get_attr_desc_a(param_1,9,1,0);
    uVar8 = 0;
    if (iVar2 != 0) {
      uVar8 = (uint)**(ushort **)(iVar2 + 6);
    }
    uVar4 = alarms_get_alarm_table_size(param_1);
    if (uVar8 < uVar4) {
      puVar5 = (undefined1 *)malloc(0xc);
    }
    else {
      puVar5 = (undefined1 *)alarms_alarm_table_pop_earliest_entry(param_1);
    }
    if (puVar5 == (undefined1 *)0x0) {
      return 0x101;
    }
    *(undefined4 *)(puVar5 + 8) = 0;
    *puVar5 = param_2;
    uVar6 = *puVar3;
    *(undefined2 *)(puVar5 + 2) = param_3;
    *(undefined4 *)(puVar5 + 4) = uVar7;
    *(undefined4 *)(puVar5 + 8) = uVar6;
    *puVar3 = puVar5;
    iVar2 = zb_zcl_get_attr_desc_a(param_1,9,1,0);
    if (iVar2 != 0) {
      uVar1 = **(ushort **)(iVar2 + 6) + 1;
      **(ushort **)(iVar2 + 6) = uVar1;
      uVar8 = alarms_get_alarm_table_size(param_1);
      if (uVar8 < uVar1) {
        zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/zcl/esp_zigbee_zcl_alarms.c"
                  ,0x6b);
        goto _L0;
      }
    }
    uVar7 = 0;
  }
  return uVar7;
}

