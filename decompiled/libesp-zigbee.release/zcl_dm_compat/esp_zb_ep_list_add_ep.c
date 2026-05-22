/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee.release -> zcl_dm_compat.o -> esp_zb_ep_list_add_ep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

esp_err_t esp_zb_ep_list_add_ep
                    (esp_zb_ep_list_t *ep_list,esp_zb_cluster_list_t *cluster_list,
                    esp_zb_endpoint_config_t endpoint_config)

{
  byte bVar1;
  undefined1 uVar2;
  undefined4 unaff_retaddr;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  esp_err_t eVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  undefined4 in_a2;
  undefined4 in_a3;
  
  while( true ) {
    *(undefined4 *)((int)register0x00002008 + -4) = unaff_retaddr;
    *(undefined4 *)((int)register0x00002008 + -0x14) = in_a3;
    if (cluster_list != (esp_zb_cluster_list_t *)0x0) {
      *(undefined2 *)&cluster_list[3].cluster_list =
           *(undefined2 *)((int)register0x00002008 + -0x14);
      bVar1 = *(byte *)((int)&cluster_list[3].cluster_list + 2);
      *(char *)&cluster_list[2].cluster_list = (char)in_a2;
      uVar6 = (undefined2)((uint)in_a2 >> 0x10);
      *(undefined2 *)((int)&cluster_list[2].cluster_list + 2) = uVar6;
      *(byte *)((int)&cluster_list[3].cluster_list + 2) =
           bVar1 & 0xf0 | (byte)((uint)in_a3 >> 0x10) & 0xf;
      *(char *)&cluster_list[-1].cluster_list = (char)in_a2;
      *(undefined2 *)((int)&cluster_list[-1].cluster_list + 2) = uVar6;
      cluster_list[6].cluster_list = (void *)0x0;
      ezb_af_device_add_endpoint_desc(cluster_list + -1);
      eVar3 = esp_zigbee_err_to_esp();
      return eVar3;
    }
    DAT_0000000c = 0;
    ebreak();
    *(undefined4 *)((int)register0x00002008 + -0x28) = unaff_s0;
    *(undefined4 *)((int)register0x00002008 + -0x2c) = unaff_s1;
    *(undefined4 *)((int)register0x00002008 + -0x24) = unaff_retaddr;
    *(undefined4 *)((int)register0x00002008 + -0x38) = in_a2;
    *(undefined4 *)((int)register0x00002008 + -0x34) = in_a3;
    cluster_list = esp_zb_zcl_cluster_list_create();
    uVar4 = basic_cluster_create(0);
    cluster_list_add_basic_cluster(cluster_list,uVar4,1);
    uVar5 = identify_cluster_create(0);
    uVar4 = 0x10eba;
    cluster_list_add_identify_cluster(cluster_list,uVar5,1);
    if (cluster_list == (esp_zb_cluster_list_t *)0x0) break;
    uVar2 = *(undefined1 *)&cluster_list[-1].cluster_list;
    *(byte *)((int)&cluster_list[-1].cluster_list + 1) =
         *(byte *)((int)&cluster_list[-1].cluster_list + 1) | 1;
    ezb_zcl_alarms_cluster_client_init(uVar2);
    ezb_zcl_identify_cluster_client_init(*(undefined1 *)&cluster_list[-1].cluster_list);
    ezb_zcl_groups_cluster_client_init(*(undefined1 *)&cluster_list[-1].cluster_list);
    ezb_zcl_scenes_cluster_client_init(*(undefined1 *)&cluster_list[-1].cluster_list);
    ezb_zcl_door_lock_cluster_client_init(*(undefined1 *)&cluster_list[-1].cluster_list);
    ezb_zcl_temperature_measurement_cluster_client_init
              (*(undefined1 *)&cluster_list[-1].cluster_list);
    ezb_zcl_ias_ace_cluster_client_init(*(undefined1 *)&cluster_list[-1].cluster_list);
    ezb_zcl_ias_zone_cluster_client_init(*(undefined1 *)&cluster_list[-1].cluster_list);
    ezb_zcl_thermostat_cluster_client_init(*(undefined1 *)&cluster_list[-1].cluster_list);
    zb_zcl_custom_cluster_init(*(uint8_t *)&cluster_list[-1].cluster_list);
    unaff_s0 = *(undefined4 *)((int)register0x00002008 + -0x28);
    in_a2 = *(undefined4 *)((int)register0x00002008 + -0x38);
    in_a3 = *(undefined4 *)((int)register0x00002008 + -0x34);
    unaff_retaddr = *(undefined4 *)((int)register0x00002008 + -0x24);
    unaff_s1 = *(undefined4 *)((int)register0x00002008 + -0x2c);
    register0x00002008 = (BADSPACEBASE *)((int)register0x00002008 + -0x20);
  }
  ebreak();
  *(undefined4 *)((int)register0x00002008 + -0x44) = uVar4;
  eVar3 = ezb_af_device_get_endpoint_desc(uRam00000001);
  if (eVar3 != 0) {
    eVar3 = eVar3 + 4;
  }
  return eVar3;
}

