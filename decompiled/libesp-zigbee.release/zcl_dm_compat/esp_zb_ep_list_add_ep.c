/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_dm_compat.o -> esp_zb_ep_list_add_ep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_ep_list_add_ep(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_retaddr;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  
  while( true ) {
    *(undefined4 *)((int)register0x00002008 + -4) = unaff_retaddr;
    *(undefined4 *)((int)register0x00002008 + -0x14) = param_4;
    if (param_2 != 0) {
      *(undefined2 *)(param_2 + 0xc) = *(undefined2 *)((int)register0x00002008 + -0x14);
      *(char *)(param_2 + 8) = (char)param_3;
      uVar4 = (undefined2)((uint)param_3 >> 0x10);
      *(undefined2 *)(param_2 + 10) = uVar4;
      *(byte *)(param_2 + 0xe) =
           *(byte *)(param_2 + 0xe) & 0xf0 | (byte)((uint)param_4 >> 0x10) & 0xf;
      *(char *)(param_2 + -4) = (char)param_3;
      *(undefined2 *)(param_2 + -2) = uVar4;
      *(undefined4 *)(param_2 + 0x18) = 0;
      ezb_af_device_add_endpoint_desc(param_2 + -4);
      iVar1 = esp_zigbee_err_to_esp();
      return iVar1;
    }
    DAT_0000000c = 0;
    ebreak();
    *(undefined4 *)((int)register0x00002008 + -0x28) = unaff_s0;
    *(undefined4 *)((int)register0x00002008 + -0x2c) = unaff_s1;
    *(undefined4 *)((int)register0x00002008 + -0x24) = unaff_retaddr;
    *(undefined4 *)((int)register0x00002008 + -0x38) = param_3;
    *(undefined4 *)((int)register0x00002008 + -0x34) = param_4;
    param_2 = esp_zb_zcl_cluster_list_create(param_1);
    uVar2 = basic_cluster_create(0);
    cluster_list_add_basic_cluster(param_2,uVar2,1);
    uVar3 = identify_cluster_create(0);
    uVar2 = 0x10eba;
    cluster_list_add_identify_cluster(param_2,uVar3,1);
    if (param_2 == 0) break;
    *(byte *)(param_2 + -3) = *(byte *)(param_2 + -3) | 1;
    ezb_zcl_alarms_cluster_client_init(*(undefined1 *)(param_2 + -4));
    ezb_zcl_identify_cluster_client_init(*(undefined1 *)(param_2 + -4));
    ezb_zcl_groups_cluster_client_init(*(undefined1 *)(param_2 + -4));
    ezb_zcl_scenes_cluster_client_init(*(undefined1 *)(param_2 + -4));
    ezb_zcl_door_lock_cluster_client_init(*(undefined1 *)(param_2 + -4));
    ezb_zcl_temperature_measurement_cluster_client_init(*(undefined1 *)(param_2 + -4));
    ezb_zcl_ias_ace_cluster_client_init(*(undefined1 *)(param_2 + -4));
    ezb_zcl_ias_zone_cluster_client_init(*(undefined1 *)(param_2 + -4));
    ezb_zcl_thermostat_cluster_client_init(*(undefined1 *)(param_2 + -4));
    zb_zcl_custom_cluster_init(*(undefined1 *)(param_2 + -4));
    unaff_s0 = *(undefined4 *)((int)register0x00002008 + -0x28);
    param_3 = *(undefined4 *)((int)register0x00002008 + -0x38);
    param_4 = *(undefined4 *)((int)register0x00002008 + -0x34);
    unaff_retaddr = *(undefined4 *)((int)register0x00002008 + -0x24);
    unaff_s1 = *(undefined4 *)((int)register0x00002008 + -0x2c);
    register0x00002008 = (BADSPACEBASE *)((int)register0x00002008 + -0x20);
  }
  ebreak();
  *(undefined4 *)((int)register0x00002008 + -0x44) = uVar2;
  iVar1 = ezb_af_device_get_endpoint_desc(uRam00000001);
  if (iVar1 != 0) {
    iVar1 = iVar1 + 4;
  }
  return iVar1;
}

