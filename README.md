# IOT

# Intelligent IoT Architecture for Continuous Vehicle Health Monitoring and Early Fault Detection

## Overview

This project presents an IoT-enabled vehicle health monitoring architecture that combines embedded sensing, edge-level processing, machine learning analysis, and cloud-based monitoring to identify abnormal vehicle operating conditions.

The system uses an ESP32 microcontroller to acquire real-time temperature and current measurements. The collected sensor data is analyzed to identify operating conditions classified as NORMAL, WARNING, and CRITICAL.

Machine learning algorithms are evaluated using experimentally collected sensor data to investigate their effectiveness in vehicle-condition classification.

## Objectives

- Develop a low-cost vehicle health monitoring architecture.
- Acquire real-time temperature and current measurements.
- Implement edge-based fault detection using ESP32.
- Analyze sensor datasets using Python.
- Compare multiple machine learning classification algorithms.
- Enable remote monitoring through the Blynk IoT platform.
- Generate alerts during abnormal operating conditions.

## System Architecture

The proposed system consists of five layers:

1. Sensing Layer – Acquires temperature and current measurements.
2. Edge Processing Layer – Processes sensor readings using ESP32.
3. Communication Layer – Transfers data using Wi-Fi.
4. Cloud Layer – Uses Blynk for remote monitoring.
5. Application Layer – Displays vehicle operating conditions and alerts.

## Hardware Components

| Component | Function |
|---|---|
| ESP32 | Main processing and communication unit |
| LM35 | Temperature measurement |
| ACS712 | Current measurement |
| BO Motor | Laboratory-scale dynamic load |
| Buzzer | Fault notification |
| Wi-Fi | Cloud communication |

## Technologies Used

- Python
- Pandas
- NumPy
- Scikit-learn
- ESP32
- Embedded C/C++
- Blynk IoT
- Machine Learning
- Data Analysis

## Machine Learning Workflow

### 1. Data Acquisition

Temperature and current measurements are collected under different operating conditions.

The collected parameters are used to construct a dataset for machine learning analysis.

### 2. Data Preprocessing

The dataset is prepared for model development through:

- Data cleaning
- Sensor measurement processing
- Feature preparation
- Data organization
- Classification label assignment

### 3. Feature Selection

The primary input parameters include:

- Temperature
- Motor current

### 4. Model Development

Five supervised machine learning algorithms are evaluated:

- Logistic Regression
- Decision Tree
- Random Forest
- Support Vector Machine (SVM)
- K-Nearest Neighbors (KNN)

### 5. Model Evaluation

The models are compared using classification accuracy.

## Experimental Results

The reported classification accuracy from the research is:

| Algorithm | Accuracy |
|---|---:|
| Random Forest | 87.3% |
| Decision Tree | 84.7% |
| Logistic Regression | 80.05% |

Random Forest achieved the highest classification accuracy among the reported models.

Note: These are the reported experimental results, not a guarantee of performance on new datasets.

## Real-Time Fault Detection

The ESP32 performs local threshold-based fault detection.

Operating conditions:

- NORMAL – Sensor readings remain within normal limits.
- WARNING – Sensor readings indicate an abnormal operating condition.
- CRITICAL – Sensor readings exceed critical thresholds.

The buzzer is activated during abnormal conditions, and sensor information is transmitted to the Blynk dashboard.

**Important:** The machine learning algorithms are evaluated independently using the collected dataset. Real-time ESP32 fault decisions use threshold-based logic rather than deployed ML inference.

## Applications

- Vehicle health monitoring
- Automotive diagnostics
- Motor condition monitoring
- Predictive maintenance research
- IoT-enabled industrial monitoring

## Research Contribution

This project demonstrates the integration of embedded sensing, IoT communication, machine learning evaluation, and edge-level fault detection in an affordable vehicle monitoring architecture.

**Publication:** An Intelligent IoT Architecture for Continuous Vehicle Health Monitoring and Early Fault Detection – ICNCCom 2026.

## Future Improvements

- Expand the dataset with additional operating conditions.
- Investigate advanced feature engineering techniques.
- Evaluate anomaly detection algorithms.
- Explore edge-based ML inference.
- Improve model generalization using additional experimental data.

## Author

**Gundu Naga Sowmya**

M.Tech – Embedded Systems  
Amrita Vishwa Vidyapeetham, Bengaluru

GitHub: [SOWMYAGUNDU1102](https://github.com/SOWMYAGUNDU1102)
