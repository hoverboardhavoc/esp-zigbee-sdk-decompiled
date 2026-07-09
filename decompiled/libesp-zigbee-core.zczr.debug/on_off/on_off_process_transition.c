/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> on_off_process_transition
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void on_off_process_transition
               (undefined4 param_1,uint param_2,int param_3,short param_4,undefined2 param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uStack_24;
  short asStack_22 [5];
  
  uStack_24 = param_5;
  asStack_22[0] = param_4;
  if ((param_2 < 2) && (iVar2 = zcl_level_action_affect_by_on_off(param_3 != 0), iVar2 != 0)) {
    return;
  }
  iVar2 = on_off_srv_get_attr_desc(param_1,0);
  iVar3 = on_off_srv_get_attr_desc(param_1,0x4001);
  iVar4 = on_off_srv_get_attr_desc(param_1,0x4002);
  if (iVar2 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0xd9,
                  "on_off_process_transition","on_off_attr_desc");
  }
  else if ((iVar3 != 0) && (iVar4 != 0)) {
    cVar1 = **(char **)(iVar2 + 8);
    if ((cVar1 != '\x01') || ((**(short **)(iVar3 + 8) == 0 || (**(short **)(iVar4 + 8) == 0)))) {
      if ((cVar1 != '\x01') || ((**(short **)(iVar3 + 8) != 0 || (**(short **)(iVar4 + 8) != 0)))) {
        if ((cVar1 != '\0') || ((**(short **)(iVar3 + 8) != 0 || (**(short **)(iVar4 + 8) == 0)))) {
          if ((cVar1 != '\0') || ((**(short **)(iVar3 + 8) != 0 || (**(short **)(iVar4 + 8) != 0))))
          {
            zcl_message_on_off_set_attr_value(param_1,param_3 != 0);
            on_off_srv_set_attr_value(param_1,0x4001,asStack_22);
            on_off_srv_set_attr_value(param_1,0x4002,&uStack_24);
            return;
          }
          if (param_2 != 0x41) {
            if (param_2 == 0x42) {
              zcl_message_on_off_set_attr_value(param_1,param_3 != 0);
              on_off_srv_set_attr_value(param_1,0x4001,asStack_22);
              on_off_srv_set_attr_value(param_1,0x4002,&uStack_24);
              return;
            }
            if (param_2 != 1) {
              return;
            }
          }
          zcl_message_on_off_set_attr_value(param_1,1);
          return;
        }
        if (param_2 != 0x41) {
          if (param_2 == 0x42) {
            asStack_22[0] = 0;
            on_off_srv_set_attr_value(param_1,0x4001,asStack_22);
            on_off_srv_set_attr_value(param_1,0x4002,&uStack_24);
            return;
          }
          if (param_2 != 1) {
            return;
          }
        }
        uStack_24 = 0;
        zcl_message_on_off_set_attr_value(param_1,1);
        on_off_srv_set_attr_value(param_1,0x4002,&uStack_24);
        return;
      }
      if (param_2 != 0x40) {
        if (param_2 == 0x42) {
          on_off_srv_set_attr_value(param_1,0x4001,asStack_22);
          on_off_srv_set_attr_value(param_1,0x4002,&uStack_24);
          return;
        }
        if (param_2 != 0) {
          return;
        }
      }
      zcl_message_on_off_set_attr_value(param_1,0);
      return;
    }
    if (param_2 != 0x40) {
      if (param_2 == 0x42) {
        if (asStack_22[0] == 0) {
          asStack_22[0] = 0;
          uStack_24 = 0;
          zcl_message_on_off_set_attr_value(param_1,0);
          on_off_srv_set_attr_value(param_1,0x4001,asStack_22);
          on_off_srv_set_attr_value(param_1,0x4002,&uStack_24);
          return;
        }
        on_off_srv_set_attr_value(param_1,0x4001,asStack_22);
        on_off_srv_set_attr_value(param_1,0x4002,&uStack_24);
        return;
      }
      if (param_2 != 0) {
        return;
      }
    }
    asStack_22[0] = 0;
    zcl_message_on_off_set_attr_value(param_1,0);
    on_off_srv_set_attr_value(param_1,0x4001,asStack_22);
    return;
  }
  zcl_message_on_off_set_attr_value(param_1,param_3 != 0);
  return;
}

