/*1. Create 3 realtime tasks each with the periodcity T1=1000ms, T2=2000ms, T3=5000ms. Also create two additional task T4 and T5 where T4 sends integer data to T5 using Messsage Queues. */

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>

QueueHandle_t Sensor_queue;

void Task1(void *pvParameters)
{
           int Sensor_data =0;
           while (1)
           {
                 Sensor_data++;
                 printf("Task1 : Sensor_data %d\n",Sensor_data);
                 xQueueSend(Sensor_queue, &Sensor_data, portMAX_DELAY);
                 vTaskDelay(1000 /portTICK_PERIOD_MS);
           }

}

 void Task2(void *pvParameters)
 {
      int recv_data =0;
      while (1)
      {
            // sending tempreture
            xQueueReceive(Sensor_queue, &recv_data, portMAX_DELAY);
            printf("Task2: recv_data %d\n", recv_data);
            vTaskDelay(2000 / portTICK_PERIOD_MS);
      }
 }

 void Task3(void *pvParameters)
 {
      int recv_data =5;
      while (1)
      {
            // sending tempreture
            xQueueReceive(Sensor_queue, &recv_data, portMAX_DELAY);
            printf("Task3: recv_data %d\n", recv_data);
            vTaskDelay(5000 / portTICK_PERIOD_MS);
      }
 }

 void Task4(void *pvParameters)
 {
      int recv_data =0;
      while (1)
      {
            // sending tempreture
            xQueueReceive(Sensor_queue, &recv_data, portMAX_DELAY);
            printf("Task4: recv_data %d\n", recv_data);
            vTaskDelay(1000 / portTICK_PERIOD_MS);
      }
 }

void Task5(void *pvParameters)
 {
      int recv_data =0;
      while (1)
      {
            // sending tempreture
            xQueueReceive(Sensor_queue, &recv_data, portMAX_DELAY);
            printf("Task5: recv_data %d\n", recv_data);
            vTaskDelay(1000 / portTICK_PERIOD_MS);
      }
 }
 void app_main()
 {
       Sensor_queue = xQueueCreate(10, sizeof(int));
       xTaskCreate(Task1, "Task1", 2048, NULL, 5, NULL);
      xTaskCreate(Task2, "Task2", 2048, NULL, 6, NULL);
      xTaskCreate(Task3, "Task3", 2048, NULL, 7, NULL);
      xTaskCreate(Task4, "Task4", 2048, NULL, 8, NULL);
      xTaskCreate(Task5, "Task5", 2048, NULL, 9, NULL);
      printf("Hello Shivangi!\n");

 }

