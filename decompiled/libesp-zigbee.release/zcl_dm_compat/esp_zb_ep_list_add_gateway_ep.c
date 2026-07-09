/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_dm_compat.o -> esp_zb_ep_list_add_gateway_ep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_ep_list_add_gateway_ep
              (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_retaddr;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 uVar4;
  
  while( true ) {
    *(undefined4 *)((int)register0x00002008 + -8) = unaff_s0;
    *(undefined4 *)((int)register0x00002008 + -0xc) = unaff_s1;
    *(undefined4 *)((int)register0x00002008 + -4) = unaff_retaddr;
    *(undefined4 *)((int)register0x00002008 + -0x18) = param_3;
    *(undefined4 *)((int)register0x00002008 + -0x14) = param_4;
    if (param_2 == 0) {
      param_2 = esp_zb_zcl_cluster_list_create(param_1);
      uVar1 = basic_cluster_create(0);
      cluster_list_add_basic_cluster(param_2,uVar1,1);
      uVar2 = identify_cluster_create(0);
      uVar1 = 0x10eba;
      cluster_list_add_identify_cluster(param_2,uVar2,1);
      if (param_2 == 0) {
        ebreak();
        *(undefined4 *)((int)register0x00002008 + -0x24) = uVar1;
        iVar3 = ezb_af_device_get_endpoint_desc(uRam00000001);
        if (iVar3 != 0) {
          iVar3 = iVar3 + 4;
        }
        return iVar3;
      }
    }
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
    unaff_s0 = *(undefined4 *)((int)register0x00002008 + -8);
    param_3 = *(undefined4 *)((int)register0x00002008 + -0x18);
    param_4 = *(undefined4 *)((int)register0x00002008 + -0x14);
    unaff_retaddr = *(undefined4 *)((int)register0x00002008 + -4);
    unaff_s1 = *(undefined4 *)((int)register0x00002008 + -0xc);
    *(undefined4 *)((int)register0x00002008 + -4) = unaff_retaddr;
    *(undefined4 *)((int)register0x00002008 + -0x14) = param_4;
    if (param_2 != 0) break;
    DAT_0000000c = 0;
    ebreak();
    register0x00002008 = (BADSPACEBASE *)((int)register0x00002008 + -0x20);
  }
  *(undefined2 *)(param_2 + 0xc) = *(undefined2 *)((int)register0x00002008 + -0x14);
  *(char *)(param_2 + 8) = (char)param_3;
  uVar4 = (undefined2)((uint)param_3 >> 0x10);
  *(undefined2 *)(param_2 + 10) = uVar4;
  *(byte *)(param_2 + 0xe) = *(byte *)(param_2 + 0xe) & 0xf0 | (byte)((uint)param_4 >> 0x10) & 0xf;
  *(char *)(param_2 + -4) = (char)param_3;
  *(undefined2 *)(param_2 + -2) = uVar4;
  *(undefined4 *)(param_2 + 0x18) = 0;
  ezb_af_device_add_endpoint_desc(param_2 + -4);
  iVar3 = esp_zigbee_err_to_esp();
  return iVar3;
}

