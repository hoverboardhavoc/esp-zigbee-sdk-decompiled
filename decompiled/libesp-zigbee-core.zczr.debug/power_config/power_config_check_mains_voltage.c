/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> power_config.o -> power_config_check_mains_voltage
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void power_config_check_mains_voltage(uint8_t ep_id,void *new_value)

{
  ushort uVar1;
  undefined3 in_register_00002029;
  int iVar2;
  int iVar3;
  
  if (new_value != (void *)0x0) {
                    /* WARNING: Load size is inaccurate */
    uVar1 = *new_value;
    iVar2 = zcl_get_attr_desc(1,0x10,0);
    if (iVar2 != 0) {
      iVar3 = zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),1,0x11,0);
      if (((iVar3 != 0) && (uVar1 < **(ushort **)(iVar3 + 8))) &&
         (**(ushort **)(iVar3 + 8) != 0xffff)) {
        **(byte **)(iVar2 + 8) = **(byte **)(iVar2 + 8) | 1;
        power_config_alarm(ep_id,'\0');
      }
      iVar3 = zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),1,0x12,0);
      if ((iVar3 != 0) && (**(ushort **)(iVar3 + 8) < uVar1)) {
        **(byte **)(iVar2 + 8) = **(byte **)(iVar2 + 8) | 2;
        power_config_alarm(ep_id,'\x01');
      }
    }
  }
  return;
}

